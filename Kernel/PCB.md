PCB
=======

Process Control Block

它放在RAM(运行内存)里并包含着进程的信息。每个进程都把自己的信息放在task_struct数据结构里。

Take kernel 4.14 as example.

**从这时候发现，还是Chinese更亲切**


task_struct 结构体定义在

[sched.h](https://elixir.bootlin.com/linux/v4.14.181/source/include/linux/sched.h)

5.X的内核又改了，task_struct 位置不在这个头文件里



##调度数据成员##

```
(1) volatile long states;
表示进程的当前状态:
 TASK_RUNNING:正在运行或在就绪队列run-queue中准备运行的进程，实际参与进程调度。
 TASK_INTERRUPTIBLE:处于等待队列中的进程，待资源有效时唤醒，也可由其它进程通过信号(signal)或定时中断唤醒后进入就绪队列run-queue。
 TASK_UNINTERRUPTIBLE:处于等待队列中的进程，待资源有效时唤醒，不可由其它进程通过信号(signal)或定时中断唤醒。
 TASK_ZOMBIE:表示进程结束但尚未消亡的一种状态(僵死状态)。此时，进程已经结束运行且释放大部分资源，但尚未释放进程控制块。
TASK_STOPPED:进程被暂停，通过其它进程的信号才能唤醒。导致这种状态的原因有二，或者是对收到SIGSTOP、SIGSTP、SIGTTIN或SIGTTOU信号的反应，或者是受其它进程的ptrace系统调用的控制而暂时将CPU交给控制进程。
 TASK_SWAPPING: 进程页面被交换出内存的进程。

Said by Kernel 

/*
 * Task state bitmask. NOTE! These bits are also
 * encoded in fs/proc/array.c: get_task_state().
 *
 * We have two separate sets of flags: task->state
 * is about runnability, while task->exit_state are
 * about the task exiting. Confusing, but this way
 * modifying one set can't modify the other one by
 * mistake.
 */

(2) unsigned long flags;
进程标志:
?PF_ALIGNWARN 打印对齐警告信息。
?PF_PTRACED 被ptrace系统调用监控。
?PF_TRACESYS 正在跟踪。
?PF_FORKNOEXEC 进程刚创建，但还没执行。
?PF_SUPERPRIV 超级用户特权。
?PF_DUMPCORE dumped core。
?PF_SIGNALED 进程被信号(signal)杀出。
?PF_STARTING 进程正被创建。
?PF_EXITING 进程开始关闭。
?PF_USEDFPU 该进程使用FPU(SMP only)。
?PF_DTRACE delayed trace (used on m68k)。

(3) long priority;
进程优先级。 Priority的值给出进程每次获取CPU后可使用的时间(按jiffies计)。优先级可通过系统调用sys_setpriorty改变(在kernel/sys.c中)。

(4) unsigned long rt_priority;
rt_priority 给出实时进程的优先级，rt_priority+1000给出进程每次获取CPU后可使用的时间(同样按jiffies计)。实时进程的优先级可通过系统 调用sys_sched_setscheduler()改变(见kernel/sched.c)。

(5) long counter;
在 轮转法调度时表示进程当前还可运行多久。在进程开始运行是被赋为priority的值，以后每隔一个tick(时钟中断)递减1，减到0时引起新一轮调 度。重新调度将从run_queue队列选出counter值最大的就绪进程并给予CPU使用权，因此counter起到了进程的动态优先级的作用 (priority则是静态优先级)。

(6) unsigned long policy;
该进程的进程调度策略，可以通过系统调用sys_sched_setscheduler()更改(见kernel/sched.c)。调度策略有:
SCHED_OTHER 0 非实时进程，基于优先权的轮转法(round robin)。
SCHED_FIFO 1 实时进程，用先进先出算法。
SCHED_RR 2 实时进程，用基于优先权的轮转法。

	#define SCHED_NORMAL		0
	#define SCHED_FIFO		1
	#define SCHED_RR		2
	#define SCHED_BATCH		3
	/* SCHED_ISO: reserved but not implemented yet */
	#define SCHED_IDLE		5
	#define SCHED_DEADLINE		6
```



