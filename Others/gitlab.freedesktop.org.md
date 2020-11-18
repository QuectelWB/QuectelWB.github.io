gitlab.freedesktop.org
========

mmcli
-----

关于ModemManager 的源码

git@gitlab.freedesktop.org:mobile-broadband/ModemManager.git

https://gitlab.freedesktop.org/mobile-broadband/ModemManager.git

https://www.freedesktop.org/wiki/Software/ModemManager/

http://www.freedesktop.org/software/ModemManager/

http://cgit.freedesktop.org/ModemManager/ModemManager

编译libqmi
-------

报错

	
	../../../src/libqmi-glib/.libs/libqmi-glib.so: undefined reference to `g_udev_device_get_sysfs_path'
	../../../src/libqmi-glib/.libs/libqmi-glib.so: undefined reference to `g_udev_client_new'
	../../../src/libqmi-glib/.libs/libqmi-glib.so: undefined reference to `g_udev_client_get_type'
	../../../src/libqmi-glib/.libs/libqmi-glib.so: undefined reference to `g_udev_device_get_parent'
	../../../src/libqmi-glib/.libs/libqmi-glib.so: undefined reference to `g_udev_client_query_by_subsystem_and_name'
	
	collect2: error: ld returned 1 exit status
	
	Makefile:454: recipe for target 'test-utils' failed
	make[4]: *** [test-utils] Error 1



Carl大神
----

[Quectel Carl](https://gitlab.freedesktop.org/carlyin)


