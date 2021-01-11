Wine
=======

1.安装wine
-----

略 (源码安装和apt-get install 方式)

2.wine使用的串口
-----

	ln -s /dev/ttyUSB0 ~/.wine/dosdevices/com1



3.cmds:
----
	# wine QMulti_DL_CMD_V1.6.exe 1 460800 ../../quectel/firmware/M95FAR03A05/QUECTEL61M_MOD_2432_11C_BB.cfg


SomeBugs
-----

[Bug 29011] New: Non-standard serial baud rates are not reported correctly

https://www.winehq.org/pipermail/wine-bugs/2011-November/299132.html

Replacing the offending lines in dlls/ntdll/serial.c: get_baud_rate with "sbr->BaudRate = speed; break;", removes the error, and the program operates correctly
即需要修改wine源码，重新安装wine.

ubuntu 上通过apt-get install wine安装的是1.6.2版本，存在以上bug

自行编译wine3.0及以上版本实测没有问题


