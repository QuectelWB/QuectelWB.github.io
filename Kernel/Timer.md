Timer
======

内核时间
------

HZ 是一个和平台相关的全局变量。

https://elixir.bootlin.coam/linux/v4.9.241/source/include/uapi/asm-generic/param.h#L5

	#ifndef HZ
	#define HZ 100
	#endif

https://elixir.bootlin.com/linux/v4.9.241/source/arch/alpha/include/uapi/asm/param.h#L4
	
	#define HZ		1024

一般情况

	#define HZ 1000

表示1秒时钟中断产生1000次。

jiffies记录了自系统启动后产生的节拍的总数。jiffies一秒内增加的数量等于HZ

短时间延时用ndekay、udelay、mdelay
长时间延时，用当前jiffies和目标jiffies值比较

	unsigned long timeout = jiffies +2 * HZ;
	while(time_before(jiffies,timeout));


time_list
-------

	struct timer_list {
		/*
		 * All fields that change during normal runtime grouped to the same cacheline
	 	*/
		struct list_head entry;
		unsigned long expires;		//超时的Jiffies
		struct tvec_base *base;

		void (*function)(unsigned long); //超时的时候处理的函数
		unsigned long data;

		int slack;

	#ifdef CONFIG_TIMER_STATS
		int start_pid;
		void *start_site;
		char start_comm[16];
	#endif
	#ifdef CONFIG_LOCKDEP
		struct lockdep_map lockdep_map;
	#endif
	};


操作函数

init_timer
add_timer
mod_timer
del_timer

example
------



