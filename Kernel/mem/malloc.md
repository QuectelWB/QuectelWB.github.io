malloc
=====

kernel malloc
------

在应用程序中获取内存通常使用函数malloc()，但在设备驱动程序中动态开辟内存可以以字节或页面为单位。其中，以字节为单位分配内存的函数有kmalloc()，注意的是，kmalloc()函数返回的是物理地址，而malloc()等返回的是线性虚拟地址，因此在驱动程序中不能使用malloc()函数。与malloc()不同，kmalloc()申请空间有大小限制。长度是2的整次方，并且不会对所获取的内存空间清零。
以页为单位分配内存的函数如下所示：
	
	get_zeroed_page()：获得一个已清零页面。
	get_free_page()：获得一个或几个连续页面。
	get_dma_pages()：获得用于DMA传输的页面。

与之相对应的释放内存用也有kfree()或free_page函数族。


<table border="1">

<tr> 
<td>头文件</td> 
<td> #include<linux/malloc.h> </td>
</tr>
<tr>

<td>函数原型</td>
<td> void* kmalloc(unsigned int len,int flags) </td>

</tr>

<tr>

<td>len</td> 
<td> </td>

</tr>

<tr>

<td>GFP_KERNEL 内核内存通常的分配方法，会引发睡眠 </td>
<td>GFP_KERNEL 内核内存通常的分配方法，会引发睡眠 </td>

</tr>

<tr>
<td>返回值</td>
<td> 成功写入的数据长度，失败返回 -EFAULT </td>
</tr>



</table>



malloc 和 slab 的关联
----



:)
