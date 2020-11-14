

__devinit
----
include/linux/init.h

   通过module_init() 和module_exit() 函数调用的函数就需要使用__init 和__exit 宏来标记。

   pci_driver 数据结构不需标记。

   probe() 和remove() 函数应该使用__devinit 和__devexit 标记，且只能标记probe() 和remove()

   如果remove() 使用__devexit 标记，则在pci_driver 结构中要用__devexit_p(remove) 来引用remove() 函数。

   如果你不确定需不需要添加优化宏则不要添加。



kernel3.8以后,把: __devinit, __devinitdata, __devinitconst, __devexit, __devexitdata, __devexitconst 这些都去掉了。


