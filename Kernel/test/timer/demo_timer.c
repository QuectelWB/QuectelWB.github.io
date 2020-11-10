#include <linux/module.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
 
void time_pre(struct timer_list *timer);
struct timer_list mytimer;

// DEFINE_TIMER(mytimer, time_pre);
void time_pre(struct timer_list *timer)
{
     printk("%s\n", __func__);
     mytimer.expires = jiffies + 500 * HZ/1000;  // 500ms 运行一次
     mod_timer(&mytimer, mytimer.expires);       // 2.2 如果需要周期性执行任务，在定时器回调函数中添加 mod_timer

              
              // 驱动接口
int __init chr_init(void)
{
      timer_setup(&mytimer, time_pre, 0);        // 1. 初始化
      mytimer.expires = jiffies + 500 * HZ/1000;
      add_timer(&mytimer);                       // 2.1 向内核中添加定时器
      printk("init success\n");
     return 0;
}
                                   
void __exit chr_exit(void)
{
      if(timer_pending(&mytimer))
       {
          del_timer(&mytimer);    // 3.释放定时器
      }
      printk("exit Success \n");
}
                                                            
module_init(chr_init);
module_exit(chr_exit);
                                            
MODULE_LICENSE("GPL");
MODULE_AUTHOR("XXX");
MODULE_DESCRIPTION("a simple char device example");}
