vm.min_free_kbytes
======

内存最安全的阈值

当请求分配内存时，如果有足够的内存，则分配成功。如果没有，则要阻塞，释放内存，再来分配内存。原子请求不能被阻塞，如果分配不到，则失败。内核为了尽量避免原子请求失败，预留了一个页池框，在内存不足时使用。这个页池框的大小就是min_free_kbytes。


echo 500000 > /proc/sys/vm/min_free_bytes

具体含义：保留500M的内存空间，但是由于系统的内存才256MB，导致系统出现kernel panic，系统崩溃了


[vm.min_free_kbytes 设置过高，导致 kswapd0 消耗大量 CPU](https://www.jianshu.com/p/20a627abe05e)

[LINUX tmpfs 空间使用未达到100% , 内存也未占满。 执行任何命令提示 bash: fork: Cannot allocate memory 过几秒时间系统会自动重启。](https://developer.aliyun.com/article/762292)

	1.首先判断客户是否内存不足导致，每次执行测试操作后，free 结果显示可用内存是有的

	2.当进程Process 比较多，导致无法分配pid，也会提示Cannot allocate memory，执行命令pstree -a | wc -l 统计下进程数，排除进程数过多导致的内存无法分配




