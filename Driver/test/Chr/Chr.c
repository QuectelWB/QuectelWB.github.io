#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/uaccess.h>
#include<linux/string.h>
#include<linux/ioport.h>
#include<asm/io.h>
#include<linux/init.h>
#include<linux/device.h>

#define  GPJ2CON_PA 0xe0200280
#define  GPJ2DAT_PA 0xe0200280
unsigned int *GPJ2CON_VA;
unsigned int *GPJ2DAT_VA;
struct cdev chrdev;
struct resource *res;
struct class *cla;
struct device *dev;
unsigned int TestMajor=0;
unsigned int TestMinor=0;
dev_t dev_no;
int ret;

int testopen(struct inode *inode,struct file *file)
{
    unsigned int a = ioread32(GPJ2CON_VA);
    a |= 0x1111;
    iowrite32(a,GPJ2CON_VA);
    printk("cdev init\n");
    return 0;

}
ssize_t testwrite(struct file *file, const char __user *usr, size_t len, loff_t *off)
{
    unsigned int a;

    copy_from_user(&a,usr,len);
    iowrite32(a,GPJ2DAT_VA);


}
ssize_t testread(struct file *file, char __user *usr, size_t len, loff_t *off)
{
    unsigned int a = ioread32(GPJ2DAT_VA);
    copy_to_user(usr,&a,len);


}
int testrelease(struct inode *inode, struct file *file)
{
    printk("close\n");
    return 0;

}

struct file_operations fops=
{
    .owner=THIS_MODULE,
    .open = testopen,
    .write = testwrite,
    .read = testread,
    .release = testrelease,
};
static int __init test_init(void)
{
    dev_no = MKDEV(TestMajor,TestMinor);
    if(dev_no>0)
    {
        ret = register_chrdev_region(dev_no,1,"chrdev_test");
    }
    else
    {
        alloc_chrdev_region(&dev_no,0,1,"chrdev_test");
    }
    if(ret<0)
    {
        return ret;
    }
    cdev_init(&chrdev,&fops);
    chrdev.owner=THIS_MODULE;
    cdev_add(&chrdev,dev_no,1);
    res = request_mem_region(GPJ2CON_PA,8,"gpj2_led");
    GPJ2CON_VA = ioremap(GPJ2CON_PA,8);
    GPJ2DAT_VA = GPJ2CON_VA + 1;
    cla = class_create(THIS_MODULE,"led_class");
    if(cla == NULL)
    {
        printk("class_creat() error!\n");
    }
    dev = device_create(cla,NULL,dev_no,NULL,"chrdev_test");
    if(dev == NULL)
    {
        printk("device_creat() error!\n");
    }

    return 0;
}

static int __exit test_exit(void)
{
    unregister_chrdev_region(dev_no,1);
    cdev_del(&chrdev);
    iounmap(GPJ2CON_VA);
    release_mem_region(GPJ2CON_PA,8);
    device_destroy(cla,dev_no);
    class_destroy(cla);
    return 0;
}

module_init(test_init);
module_exit(test_exit);


MODULE_AUTHOR("FENG");
MODULE_DESCRIPTION("the first module of char drivers");
MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");

