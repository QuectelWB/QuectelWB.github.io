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




