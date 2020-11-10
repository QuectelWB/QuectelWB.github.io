#makefile
 obj-m := drv_test.o
 KERNEL_DIR := /lib/modules/$(shell uname -r)/build
 PWD := $(shell pwd)
 
.PHONY:clean
  
all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
  	 
clean:
	rm -f *.o *.ko *.mod.c *.mod.o *.symvers
