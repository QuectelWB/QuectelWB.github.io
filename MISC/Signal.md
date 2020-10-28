SIGNAL
======

From

[https://linoxide.com/linux-how-to/linux-signals-part-1](https://linoxide.com/linux-how-to/linux-signals-part-1/)

[https://linoxide.com/linux-how-to/linux-kill-command-examples/](https://linoxide.com/linux-how-to/linux-kill-command-examples/)

Signals in Linux is a very important concept to understand. This is because signals are used in some of the common activities that you do through Linux command line. For example, whenever you press <code/>Ctrl+c</code> to terminate an executing command from command line, you use signals.

Whenever you use 'kill -9 [pid]' to kill a process, you use signals. So, it is very useful to know at least the basics of signals and that is exactly what we will discuss in this tutorial.

A signal is nothing but a way of communicating a message from one process to another. These messages are popularly known as notifications which the receiving process is free to process, ignore or leave it up to the OS to take default action (more on these options later). A notification sent by the sender process to the receiving process can be of various types. For example, a notification can be to kill the receiving process or let it know that it has accessed an invalid memory area or it can be a notification of the availability of a resource (that was busy earlier) etc. So, you can see that signals are nothing but just another way of IPC (inter Process Communication).

Signals are important, in-fact very important because they drive some of the most popular programming and system administration activities. 

For example, let's take the example of a debugger. Most of the programmers use a debugger to debug their program code while it is executing. If you would have ever used a debugger, you would know that breakpoints are used to halt the execution of a program at specified lines of code.

What makes a program aware that a breakpoint has been hit and it needs to halt the execution? 

Yes, it is a signal (SIGSTOP) that is sent to the program in this case. And when the user is done with debugging, a signal (SIGCONT) is sent to the program -- after which the program continues the execution.


Different Types Of Signals
-----

	root@m:/# kill -l

	 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
	 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
	11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
	16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
	21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
	26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
	31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
	38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
	43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
	48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
	53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
	58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
	63) SIGRTMAX-1  64) SIGRTMAX


Difference between SIGTERM, SIGKILL, SIGINT, SIGQUIT
------

SIGQUIT

On POSIX-compliant platforms, SIGQUIT is the signal sent to a process by its controlling terminal when the user requests that the process perform a core dump. SIGQUIT can usually be induced with Control-\. On Linux, one may also use Ctrl-4 or, on the virtual console, the SysRq key.

SIGTERM
SIGTERM is the default signal sent to a process by the kill or killall commands. It causes the termination of a process, but unlike the SIGKILL signal, it can be caught and interpreted (or ignored) by the process. Therefore, SIGTERM is akin to asking a process to terminate nicely, allowing cleanup and closure of files. For this reason, on many Unix systems during shutdown, init issues SIGTERM to all processes that are not essential to powering off, waits a few seconds, and then issues SIGKILL to forcibly terminate any such processes that remain.

SIGINT

On POSIX-compliant platforms, SIGINT is the signal sent to a process by its controlling terminal when a user wishes to interrupt the process. SIGINT is sent when the user on the process' controlling terminal presses the interrupt the running process key  typically Control-C, but on some systems, the "delete" character or "break" key.

SIGKILL

On POSIX-compliant platforms, SIGKILL is the signal sent to a process to cause it to terminate immediately. When sent to a program, SIGKILL causes it to terminate immediately. In contrast to SIGTERM and SIGINT, this signal cannot be caught or ignored, and the receiving process cannot perform any clean-up upon receiving this signal.


Programming
------

How a Program Handles Signals?
A program can handle signals in the following three ways:

A program may provide its own signal handler for handling a particular signal - This is especially important in those cases where a program has to perform some tasks (for example - memory clean-up activities) in response to the received signal. A signal handler is nothing but a function defined in the program code that gets executed automatically (actually it gets triggered by the OS kernel) when a signal is received by the program.
A Program may do nothing on receipt of a signal - Every signal has a default action associated with it. In a scenario where a program just doesn't care for a signal, the default action corresponding to that particular signal is taken by the OS kernel.
A program may choose to ignore a signal - In this situation, the signal (or set of signals) are blocked and are hence not delivered to the program. A program may choose to ignore signals which -- the programmer thinks -- are irrelevant to it.


Examples
------

[http://www.yolinux.com/TUTORIALS/C++Signals.html](http://www.yolinux.com/TUTORIALS/C++Signals.html)


``` 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
 
// Define the function to be called when ctrl-c (SIGINT) signal is sent to process

void signal_callback_handler(int signum)
{
   printf("Caught signal %d\n",signum);
   // Cleanup and close up stuff here
   // Terminate program
   exit(signum);
}
 
int main()
{
   // Register signal and signal handler
   signal(SIGINT, signal_callback_handler);
   while(1)
   {
      printf("Program processing stuff here.\n");
      sleep(1);
   }
   return EXIT_SUCCESS;
}

```
