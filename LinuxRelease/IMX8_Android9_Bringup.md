Android 10 On IMX8
======

Source Code from

https://pan.baidu.com/s/1ldI06aZYT1E2BrBoba7Dqg 提取码 

编译环境 2021.1.14
------

参考
<br>**OKMX8MM-C（Android）用户资料-20200302\原厂资料\Android_User's_Guide.pdf**
<br>**OKMX8MM-C（Android）用户资料-20200302\原厂资料\Android_Quick_Start_Guide.pdf**
<br>**OKMX8MM-C（Android）用户资料-20200302\手册\OKMX8MM-C_Android_用户手册_V1.1_2020.03.02.pdf**

### Ubuntu 环境

官方文档要求 Ubuntu 16.04 X64

	$ sudo add-apt-repository ppa:openjdk-r/ppa 
	$ sudo apt-get update 
	$ sudo apt-get install uuid \ 
	uuid-dev \ 
	zlib1g-dev \ 
	liblz-dev \ 
	liblzo2-2 \ 
	liblzo2-dev \ 
	lzop \ 
	git-core curl \ 
	u-boot-tools \ 
	mtd-utils \ 
	android-tools-fsutils \ 
	openjdk-8-jdk \ 
	device-tree-compiler \ 
	gdisk \ 
	m4 \ 
	libz-dev

jdk 要求是1.8版本

解压源码

	$ cd /home/forlinx/imx8mm/ 
	$cat OK8MM-android-source.tar.bz2_a* > OK8MM-android-source.tar.bz2 
	$ tar -xvf OK8MM-android-source.tar.bz2 


### 自定义docker环境

按照Ubuntu 环境，自定义docker环境，并且支持ssh 登录docker 容器中的ubuntu

已经上传到docker.io

下载
	
	docker pull quectel/imx8_android9:latest

用户名 imx8 密码 quectel123

编译Android
-----

运行docker 环境

	android@q-OptiPlex-7070:~$ docker run -d --name imx8 -v /home/android/IMX8_Android9:/home/imx8/imx8_Android -v /etc/localtime:/etc/localtime:ro   -v
	 /etc/timezone:/etc/timezone:ro --device=/dev/loop-control:/dev/loop-control --device=/dev/loop0:/dev/loop0 --cap-add SYS_ADMIN -p 6666:22  --privil
	eged  ubuntu:16_jdk1.8  /usr/sbin/sshd -D
	57c2bf9c7ccefaa4701f006c420d3d5ededfdf3f0ea0b0655772d42c21b566e7
	android@q-OptiPlex-7070:~$
	android@q-OptiPlex-7070:~$
	android@q-OptiPlex-7070:~$ docker ps
	CONTAINER ID   IMAGE              COMMAND               CREATED         STATUS         PORTS                  NAMES
	57c2bf9c7cce   ubuntu:16_jdk1.8   "/usr/sbin/sshd -D"   6 seconds ago   Up 3 seconds   0.0.0.0:6666->22/tcp   imx8
	android@q-OptiPlex-7070:~$ ls
	模板  camdroid  IMX8_Android9  Khadas  Tiny4412_android5.1  v3s_camdroid.zip

SSH远程连接到

	ssh -P 6666 ${HOST_IP}

	PS D:\BaiduNetdiskDownload\imx8-android> ssh -p 6666 imx8@10.66.83.84
	The authenticity of host '[10.66.83.84]:6666 ([10.66.83.84]:6666)' can't be established.
	ECDSA key fingerprint is SHA256:vhkbWtZEDaEjXzh6phneA4VSDB3hLSZdvOr8ZD/zYvw.
	Are you sure you want to continue connecting (yes/no)? yes
	Warning: Permanently added '[10.66.83.84]:6666' (ECDSA) to the list of known hosts.
	imx8@10.66.83.84's password:
	Welcome to Ubuntu 16.04.7 LTS (GNU/Linux 5.4.0-58-generic x86_64)

	
在docker容器中编译		

	$ cd /home/imx8/imx8_Android/OK8MM-android-source 
	$ source build/envsetup.sh 
	$ lunch evk_8mm-userdebug
	$ make -j8


烧录
------

分区表

| 分区索引 	| 		名称 	| 		偏移 	| 	大小 	| 文件系统 			|  			内容 	|
| ---- 		| ---- 			| ---- 			| ---- 		| ---- 				| ---- 				|
| NA 		| Bootloader 		| 33KB 			| 4MB 		| NA				| bootloader 			|
| 1 		| dtbo_a 		| 8MB 			| 4MB 		| NA 				| dtbo.img 			|
| 2 		| dtbo_b 		| Follow dtbo_a 	| 4MB 		| NA				| dtbo.img 			|
| 3 		| boot_a 		| Follow dtbo_b 	| 48MB 		| boot.img(kernel+ramdisk)	| boot.img 			|
| 4 		| boot_b		| Follow boot_a		| 48MB 		| boot.img(kernel+ramdisk) 	| boot.img		 	|
| 5 		| system_a		| Follow boot_b		| 1536MB 	| ext4 挂载在 	/system		| Android系统文件/system目录 	|
| 6 		| system_b		| Follow system_a	| 1536MB 	| ext4 挂载在   /system 	| Android系统文件/system目录 	|
| 7 		| misc			| Follow system_b	| 4MB 		| NA 				| 为了恢复保存bootloader信息	|
| 8 		| metadata		| Follow misc		| 2MB 		| NA 				| For system slide show		|
| 9 		| presistdata		| Follow metadata	| 1MB 		| NA 				| Option to operate unlock metadata |
| 10 		| vendor_a		| Follow presistdata	| 256MB 	| ext4.挂载在/vendor		| vendor.img			|
| 11 		| vendor_b		| Follow vendor_a	| 256MB 	| ext4.挂载在/vendor		| vendor.img			|
| 12 		| userdata		| Follow vendor_b	| 剩余全部 	| ext4.挂载在/data		| 应用程序数据			|
| 13 		| fbmisc 		| Follow userdata	| 1MB 		| NA 				| 保存lock/unlock状态		|
| 14 		| vbmeta_a 		| Follow fbmisc 	| 1MB 		| NA 				| 保存verify boot's metadata 	|
| 15 		| vbmeta_b 		| Follow vbmeta_a 	| 1MB 		| NA 				| 保存verify boot's metadata 	|

ab分区方式


内核驱动移植
----














RIL库移植
-----






烧录
-----

在Linux上烧录,用root账户，否则/tmp/目录没法写。

	uuu_imx_android_flash.bat -f imx8mm -e -c 7

uuu.exe 放到环境变量路径中；管理员权限执行

  











Android FAQs
-----

[Q]客户移植RIL驱动，发现有两个rild
[A]kill掉其中一个

[Q]hidl 
[A]

[Q]Android 怎么改router，修改默认DNS
[A]


[Q]Android 怎么修改网卡的优先顺序
[A]
