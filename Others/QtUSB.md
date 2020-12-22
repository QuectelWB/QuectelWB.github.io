QT USB
=====

[lisbusb](https://github.com/libusb/libusb/wiki)


[QT USB通信](https://blog.csdn.net/peixiuhui/article/details/76723443)


[libusb-win32](https://sourceforge.net/projects/libusb-win32/)


[libusb2](https://sourceforge.net/p/libusb-win32/wiki/Home/)


[libusb articles](https://blog.csdn.net/zxc131313a/article/details/88609913)


Qt cannot find -lGL
------

删除 /opt/Qt5.X.X/5.X/gcc_64/mkspecs/common/linux.conf 的这一句，实际并没有用到OpenGL的情况

QMAKE_LIBS_OPENGL = -lGL

或者

sudo apt-get install libgl1-mesa-dev


libusb
------

	sudo apt-get install libusb-dev
	sudo apt-get install libusb-1.0-0-dev

	#include <libusb-1.0/libusb.h>
	libusb_get_device_descriptor(dev,descriptor)
	printf("\tVENDOR(0x%x) PRODUCT(0x%x)\n", desc.idVendor, desc.idProduct);

	
	gcc test.c `pkg-config --libs --cflags libusb-1.0`


参考
[lbusb获取usb设备的idVendor(vid)，idProduct(pid)，以及Serial Number](https://blog.csdn.net/zhc10110011/article/details/46610701)

[Example Codes of libusb](https://cpp.hotexamples.com/examples/-/-/libusb_open/cpp-libusb_open-function-examples.html)

[Kakadu's example](https://github.com/Kakadu/Qt_libusb.git)

