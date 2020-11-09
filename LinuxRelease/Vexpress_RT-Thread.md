Vexpress-A9 RT-Rthread BSP
========

[https://www.rt-thread.org/document/site/application-note/setup/qemu/ubuntu/an0005-qemu-ubuntu/](https://www.rt-thread.org/document/site/application-note/setup/qemu/ubuntu/an0005-qemu-ubuntu/)


Ready
-----

git clone https://github.com/RT-Thread/rt-thread.git

sudo apt-get install scons qemu cross_compile

tom@laptop:~$ cd /tmp/
tom@laptop:/tmp$ wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-rm/6-2016q4/gcc-arm-none-eabi-6_2-2016q4-20161216-linux.tar.bz2
tom@laptop:/tmp$ tar xf ./gcc-arm-none-eabi-6_2-2016q4-20161216-linux.tar.bz2
tom@laptop:/tmp$ mv gcc-arm-none-eabi-6_2-2016q4/ /opt/
tom@laptop:/tmp$ /opt/gcc-arm-none-eabi-6_2-2016q4/bin/arm-none-eabi-gcc --version

sudo apt-get install libncurses5-dev


