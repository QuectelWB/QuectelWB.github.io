WSL 服务自动启动的正确方法
========

wsl 支持后台运行

在WSL中创建 /etc/init.wsl

	#! /bin/sh
	/etc/init.d/cron $1
	/etc/init.d/ssh $1
	/etc/init.d/supervisor $1


WIN+R <br>
shell:startup
创建Windows系统的启动脚本 debian.vbs

	Set ws = CreateObject("Wscript.Shell")
	ws.run "wsl -d debian -u root /etc/init.wsl start", vbhide


