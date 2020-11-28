TO_DO_LIST
=======

netlink 是什么怎么用?
------


户空间和内核空间的通信方式有三种：/proc、ioctl、Netlink
netlink 的优势在于双工通信



SYNOPSIS
       #include <asm/types.h>
       #include <linux/netlink.h>

       int NLMSG_ALIGN(size_t len);
       int NLMSG_LENGTH(size_t len);
       int NLMSG_SPACE(size_t len);
       void *NLMSG_DATA(struct nlmsghdr *nlh);
       struct nlmsghdr *NLMSG_NEXT(struct nlmsghdr *nlh, int len);
       int NLMSG_OK(struct nlmsghdr *nlh, int len);
       int NLMSG_PAYLOAD(struct nlmsghdr *nlh, int len);

DESCRIPTION
       <linux/netlink.h>  defines  several  standard macros to access or create a netlink datagram.  They are similar in spirit to the macros de
       fined in cmsg(3) for auxiliary data.  The buffer passed to and from a netlink socket should be accessed using only these macros.



RCU
--------

Read-Copy Update


kernel-per-CPU-kthreads
------

[kernel-per-CPU-kthreads](https://elixir.bootlin.com/linux/v4.14.181/source/Documentation/kernel-per-CPU-kthreads.txt)

	
	/proc/sys/kernel/watchdog_thresh
	










