Supervisor
======

Supervisor是一个Python编写的进程管理工具，支持Linux/Unix系统（不支持Windows），可以很方便的启动、停止、重启多个进程，可以在程序意外退出后自动重启，记录并输出所有控制台日志，免去了自己编写shell脚本的麻烦

	apt install supervisor #安装
	systemctl enable supervisor #设置开机自启
	supervisord #初始化

添加配置
-----

Supervisor的默认配置目录在/etc/supervisor/conf.d/下

	vim /etc/supervisor/conf.d/slimchat.conf #slimchat为自定义名称，下同

	[program:slimchat]
	command=npm start 启动命令
	directory=/home/wwwroot/www.slimchat.ml/SlimChat/ 目录
	autostart=true 是否自启
	autorestart=true 进程退出后是否自动重启
	stderr_logfile=/var/log/slimchat.err.log 错误日志
	stdout_logfile=/var/log/slimchat.out.log 输出日志
	user=www 用户身份
	stopsignal=INT

相关命令
-------

	supervisorctl status slimchat #查看进程状态（使用自定义的名称）

	supervisorctl stop slimchat #停止

	supervisorctl start slimchat #启动

	supervisorctl restart slimchat #重启

	supervisorctl reload #重启整个服务（注意！此命令会重启所有进程，不推荐）

	更新配置后的正确方法：

	supervisorctl reread

	supervisorctl update

FAQ
-----


Error: Another program is already listening on a port that one of our HTTP servers is configured to use. Shut this program down first before starting supervisord.

解决

	find / -name supervisor.sock
	unlink /run/supervisor.sock
	supervisord

