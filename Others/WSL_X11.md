WSL_X11_RemoteLogin
=======

	sudo apt-get update && sudo apt-get upgrade -y && sudo apt-get upgrade -y && sudo apt-get dist-upgrade -y && sudo apt-get autoremove -y

	sudo apt-get install xorg

	sudo apt-get install xfce4

	sudo apt-get install xrdp

	sudo sed -i s/port=3365/port=3365/g /etc/xrdp/xrdp.ini

	sudo echo xfce4-session >~/.xsession

	sudo service xrdp restart


	[....]Restarting Remote Desktop Protocol server: xrdp-sesman xrdp
	[20201124-19:34:09] [DEBUG] Testing if xrdp can listen on 0.0.0.0 port 3389.
	[20201124-19:34:09] [DEBUG] Closed socket 6 (AF_INET6 :: port 3389)
	. ok


	远程登录 $(IP):3389

-----------


[window10 玩转unbuntu 子系统安装WSL 图形界面，远程桌面](https://www.jianshu.com/p/344185d97476?tdsourcetag=s_pcqq_aiomsg)

:)
