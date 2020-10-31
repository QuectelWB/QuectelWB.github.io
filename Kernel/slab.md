Slab
======




slabtop
------


Linux内核需要为临时对象如任务或者设备结构和节点分配内存，缓存分配器管理着这些类型对象的缓存。现代Linux内核部署了该缓存分配器以持有缓存，称之为片。不同类型的片缓存由片分配器维护。
slabtop命令的作用就是显示实时内核片缓存信息。


my Ubuntu
-----

``` config-5.4.0-26-generic
root@m:/boot# ack SLUB
config-5.4.0-26-generic
247:CONFIG_SLUB_DEBUG=y
248:CONFIG_SLUB_MEMCG_SYSFS_ON=y
251:CONFIG_SLUB=y
257:CONFIG_SLUB_CPU_PARTIAL=y
10222:# CONFIG_SLUB_DEBUG_ON is not set
10223:# CONFIG_SLUB_STATS is not set
root@m:/boot#
root@m:/boot# ack SLAB
config-5.4.0-26-generic
250:# CONFIG_SLAB is not set
253:CONFIG_SLAB_MERGE_DEFAULT=y
254:CONFIG_SLAB_FREELIST_RANDOM=y
255:CONFIG_SLAB_FREELIST_HARDENED=y
```

difference between SLAB and SLUB
-----

LAB 分配器多年以来一直位于 Linux 内核的内存管理部分的核心地带，内核黑客们一般不愿意主动去更改它的代码，因为它实在是非常复杂，而且在大多数情况下，它的工作完成的相当不错。但是，随着大规模多处理器系统和 NUMA系统的广泛应用，SLAB 分配器逐渐暴露出自身的严重不足：

* 较多复杂的队列管理。在 SLAB 分配器中存在众多的队列，例如针对处理器的本地对象缓存队列，slab 中空闲对象队列，每个 slab 处于一个特定状态的队列中，甚至缓冲区控制结构也处于一个队列之中。有效地管理这些不同的队列是一件费力且复杂的工作。

* slab 管理数据和队列的存储开销比较大。每个 slab 需要一个 struct slab 数据结构和一个管理所有空闲对象的 kmem_bufctl_t（4 字节的无符号整数）的数组。当对象体积较少时，kmem_bufctl_t 数组将造成较大的开销（比如对象大小为32字节时，将浪费 1/8 的空间）。为了使得对象在硬件高速缓存中对齐和使用着色策略，还必须浪费额外的内存。同时，缓冲区针对节点和处理器的队列也会浪费不少内存。测试表明在一个 1000 节点/处理器的大规模 NUMA 系统中，数 GB 内存被用来维护队列和对象的引用。

* 缓冲区内存回收比较复杂。

* 对 NUMA 的支持非常复杂。SLAB 对 NUMA 的支持基于物理页框分配器，无法细粒度地使用对象，因此不能保证处理器级缓存的对象来自同一节点。
冗余的 Partial 队列。SLAB 分配器针对每个节点都有一个 Partial 队列，随着时间流逝，将有大量的 Partial slab 产生，不利于内存的合理使用。

* 性能调优比较困难。针对每个 slab 可以调整的参数比较复杂，而且分配处理器本地缓存时，不得不使用自旋锁。
调试功能比较难于使用。

为了解决以上 SLAB 分配器的不足之处，内核开发人员 Christoph Lameter 在 Linux 内核 2.6.22 版本中引入一种新的解决方案：SLUB 分配器。SLUB 分配器特点是简化设计理念，同时保留 SLAB 分配器的基本思想：每个缓冲区由多个小的 slab 组成，每个 slab 包含固定数目的对象。SLUB 分配器简化了kmem_cache，slab 等相关的管理数据结构，摒弃了SLAB 分配器中众多的队列概念，并针对多处理器、NUMA 系统进行优化，从而提高了性能和可扩展性并降低了内存的浪费。为了保证内核其它模块能够无缝迁移到 SLUB 分配器，SLUB 还保留了原有 SLAB 分配器所有的接口 API 函数。




reference
-----

[知乎.谈slab](https://zhuanlan.zhihu.com/p/61457076)

[Cache占用过多内存导致Linux系统内存不足问题排查](https://blog.csdn.net/zhongbeida_xue/article/details/78830468)


