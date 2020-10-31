#include<linux/slab.h>
#include<linux/module.h>
#include<linux/sched.h>

MODULE_LICENSE("GPL");

int __init task_init(void)
{
    struct task_struct p;
    struct mm_struct m;
    printk("sizeof task_struct = %ld,sizeof mm_struct = %ld\n",sizeof(p),sizeof(m));
    return 0;
}

void __exit task_exit(void)
{
	return;
}

module_init(task_init);
module_exit(task_exit);
