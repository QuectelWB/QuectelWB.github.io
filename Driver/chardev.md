Char Device
======

alloc_chrdev_region


向内核申请主设备号时用的，与register_chrdev_region不同的是，alloc_chrdev_region是让内核分配给我们一个尚未使用的主设备号，不是由我们自己指定的.
	
	
	dev :alloc_chrdev_region函数向内核申请下来的设备号
	
	baseminor :次设备号的起始
	
	count: 申请次设备号的个数
	
	name :执行 cat /proc/devices显示的名称



	#include <linux/module.h>       // module_init  module_exit
	#include <linux/init.h>         // __init   __exit
	#include <linux/cdev.h>
	#include <linux/fs.h>
	#define MYMAJOR     200
	#define MYNAME      "chardev_test_byHc"
	 
	 
	//DEVICE ID
	dev_t devid;
	 
	static int chardev_open(struct inode *inode, struct file *file)
	{
	    printk(KERN_INFO "chardev open\n");
	    return 0;
	}
 
	static ssize_t chardev_read(struct file *file, char __user *buf,
	          size_t size, loff_t *ppos)
	{
	    return 0;
	}
	 
	 
	static const struct file_operations chardev_fops = { 
	 
	    .open = chardev_open,
	    .read = chardev_read,
	};
 
	static struct
	{
	    struct cdev cdev;
	}chardev;
	 
	static int __init mymodule_init(void)
	{   
	    int ret = 0;
	    printk(KERN_INFO "chrdev_init helloworld init\n");
	    cdev_init(&chardev.cdev,&chardev_fops);
	        
	    alloc_chrdev_region(&devid,2,255,MYNAME);
	    printk(KERN_INFO "MAJOR Number is %d\n",MAJOR(devid));
	    printk(KERN_INFO "MINOR Number is %d\n",MINOR(devid));
	    cdev_add(&chardev.cdev,devid,255);
	        
	    return 0;
	}
	
	static void __exit mymodule_exit(void)
	{
		    printk(KERN_INFO "chrdev_exit helloworld exit\n");
		    cdev_del(&chardev.cdev);
		    unregister_chrdev_region(devid,255);
	 
	}
	 	
	 	
	module_init(mymodule_init);
	module_exit(mymodule_exit);
	 
	MODULE_LICENSE("GPL");              // 描述模块的许可证
	MODULE_DESCRIPTION("module test");  // 描述模块的介绍信息
	MODULE_ALIAS("alias xxx");          // 描述模块的别名信息

