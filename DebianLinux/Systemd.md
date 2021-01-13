Systemd
========


System-V 其实指的就是通常的那种/etc/init.d/的方式。 
-----

SystemV 和 BSD 是两种Unix风格

| | 	Sytem V	| BSD |
| ---- | ----- | ---- |
| Root脚本位置 |	/etc/init.d |	/etc/rc.d |
| 默认Shell |	Bshell |	Cshell |
| 文件系统数据 |	/etc/mnttab |	/etc/mtab |
| 内核位置 |	/UNIX |	/vmUnix |
| 打印机设备 |	lp |	rlp |
| 字符串函数 |	memcopy	 | bcopy |
| 终端初始化设置文件 |	/etc/initab |	/etc/ttys |
|  终端控制 |	termio	| termios |


通常的那些IPC方法（共享内存、消息队列、信号量）也是针对System V.


Systemd
System-V
