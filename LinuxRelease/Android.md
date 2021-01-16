AndroidBsp
=====

RIL
----
[Android RIL的Java 框架](http://mp.weixin.qq.com/s?__biz=MzIxNjU5MzAxMw==&mid=2247484836&idx=2&sn=88eecc283690db180f7f5646d6a6831c&chksm=9787e2bea0f06ba8f78999080a81942984f75b8db86e4845a6671044e613b41433d10bda71f3&mpshare=1&scene=24&srcid=1111nKtRvQyiG8zwkUUr68Aa&sharer_sharetime=1605052874338&sharer_shareid=ecace1467fd81ffbadc2260cf4ccea17#rd)

java部分
	RIL模
	Phone模块

Lineage OS on RP3B
----
参考

[LineageOS 17.1 (Android 10) for Raspberry Pi 3](https://konstakang.com/devices/rpi3/LineageOS17.1/)

[LineageOS 17.1 (Android 10) for for Raspberry Pi 4](https://konstakang.com/devices/rpi4/LineageOS17.1/)

[Ubuntu下为树莓派3B编译Android（Lineage OS）7.1.2系统](https://blog.csdn.net/babyshan1/article/details/78894600)


	repo init -u git://github.com/LineageOS/android.git -b cm-14.1

	curl --create-dirs -L -o .repo/local_manifests/manifest_brcm_rpi3.xml -O -L https://raw.githubusercontent.com/lineage-rpi/android_local_manifest/cm-14.1/manifest_brcm_rpi3.xml

	repo sync

编译kernel

	source build/envsetup.sh
	lunch lineage_rpi3-userdebug
	make ramdisk systemimage

分区1 128MB 分配给 BOOT : 用 fdisk : W95 FAT32(LBA) & Bootable, mkfs.vfat
分区2 1024MB 分配给 /system : 用 fdisk, 新建主分区
分区3 分配给  /data : 用 fdisk, mkfs.ex4

七、写入编译好的文件
1.写入系统分区

假设system分区挂载在/dev/sdb2下：

	$ cd out/target/product/rpi3
	$ sudo dd if=system.img of=/dev/sdb2 bs=1M

2.复制内核文件到boot分区

-  复制device/brcm/rpi3/boot/* 到 分区1:/
-  复制kernel/rpi/arch/arm/boot/zImage 到 分区1:/
-  复制kernel/rpi/arch/arm/boot/dts/bcm2710-rpi-3-b.dtb 到 分区1:/
-  复制kernel/rpi/arch/arm/boot/dts/overlays/vc4-kms-v3d.dtbo 到 分区1:/overlays/vc4-kms-v3d.dtbo
-  复制out/target/product/rpi3/ramdisk.img 到 分区1:/

还没尝试！！！

Android
-----






:)
