#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/task.h>
#include <linux/sched/signal.h>
//#include <linux/sched.h>

MODULE_LICENSE("GPL");


static int ps_begin(void)
{
	int KernelThreadCount = 0;
        int UserThreadCount = 0;
        struct task_struct *p;
        p = &init_task;
        for_each_process(p)
        {
             if( p->mm == NULL )
                {
                        printk("\nKernelThread Info!\n");
                        printk("comm=%s, pid=%d, state=%ld\n", p->comm, p->pid, p->state);
                       ++KernelThreadCount;
                }
             else{
	                printk("\nUserThread Info!\n");
	                printk("comm=%s, pid=%d, state=%ld\n", p->comm, p->pid, p->state);
	                ++UserThreadCount;
	        }
   }
	        printk("\nThe number of kernel Thread is:%d.\n", KernelThreadCount);
	        printk("\nThe number of User Thread is:%d.\n", UserThreadCount);
	        return 0;
}

static void ps_end(void)
{
        printk("\nExit!\n");
}
module_init( ps_begin );
module_exit( ps_end );
