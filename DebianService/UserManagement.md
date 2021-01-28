Ubuntu账户管理
======

添加新账户并加入root组
------


	sudo adduser ubuntu

	sudo adduser ubuntu sudo

当前用户改名
------
当前用户处于登录状态

	quectel@q-OptiPlex-7070:/home$ sudo su
	root@q-OptiPlex-7070:/home# usermod -l VincentW -d /home/VincentW -m q
	usermod: user q is currently used by process 1173


	root@q-OptiPlex-7070:/home# ps -elf | grep 1173
	4 S q           1173       1  0  80   0 -  5041 ep_pol 21:52 ?        00:00:00 /lib/systemd/systemd --user
	5 S q           1174    1173  0  80   0 - 42414 do_sig 21:52 ?        00:00:00 (sd-pam)
	0 S q           1179    1173  0  69 -11 - 203425 poll_s 21:52 ?       00:00:00 /usr/bin/pulseaudio --daemonize=no --log-target=journal
	0 S q           1194    1173  0  80   0 -  2055 ep_pol 21:52 ?        00:00:00 /usr/bin/dbus-daemon --session --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
	0 S q           1310    1173  0  80   0 - 76380 poll_s 21:52 ?        00:00:00 /usr/libexec/at-spi-bus-launcher
	0 S q           1320    1173  0  80   0 - 40707 poll_s 21:52 ?        00:00:00 /usr/libexec/at-spi2-registryd --use-gnome-session
	0 S q           1363    1173  0  80   0 - 60731 poll_s 21:52 ?        00:00:00 /usr/libexec/gvfsd
	0 S q           1503    1173  0  80   0 - 94584 futex_ 21:52 ?        00:00:00 /usr/libexec/gvfsd-fuse /run/user/1000/gvfs -f -o big_writes
	0 S q           1506    1173  0  80   0 - 79312 poll_s 21:52 ?        00:00:00 /usr/libexec/gvfs-udisks2-volume-monitor
	0 S q           1547    1173  0  80   0 - 59771 poll_s 21:52 ?        00:00:00 /usr/libexec/gvfs-goa-volume-monitor
	0 S q           1566    1173  0  80   0 - 79984 poll_s 21:52 ?        00:00:00 /usr/libexec/gvfs-afc-volume-monitor
	0 S q           1571    1173  0  80   0 - 60289 poll_s 21:52 ?        00:00:00 /usr/libexec/gvfs-gphoto2-volume-monitor
	0 S q           1576    1173  0  80   0 - 59720 poll_s 21:52 ?        00:00:00 /usr/libexec/gvfs-mtp-volume-monitor
	0 S q           1588    1173  0  80   0 - 68733 poll_s 21:52 ?        00:00:00 /usr/lib/x86_64-linux-gnu/bamf/bamfdaemon
	0 S q           1625    1173  0  80   0 - 39089 poll_s 21:52 ?        00:00:00 /usr/libexec/dconf-service
	0 S q           1712    1173  0  80   0 - 10996 poll_s 21:53 ?        00:00:00 /usr/lib/bluetooth/obexd
	0 S q           1721    1173  0  80   0 - 117834 poll_s 21:53 ?       00:00:00 /usr/lib/x86_64-linux-gnu/libexec/kactivitymanagerd
	0 S q           1729    1173  0  80   0 - 59106 poll_s 21:53 ?        00:00:00 /usr/bin/kglobalaccel5
	0 S q           1732    1173  0  80   0 - 41338 poll_s 21:53 ?        00:00:00 /usr/libexec/gvfsd-metadata
	0 S q           1888    1173  0  80   0 - 56808 poll_s 21:55 ?        00:00:00 /usr/sbin/kylinssoclient

因此还是要在recovery mode下修改。

/etc/passwd 和 /etc/shadow 替换


