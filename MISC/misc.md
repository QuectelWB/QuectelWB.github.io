MISC
=====

Hard to clarify...

locales
----
locale 是Ubuntu/Centos 用于语言环境本地化。

远程SSH 连了自己平板电脑上的WSL环境，Ubuntu环境的工作OK，但是Debian的WSL环境却出现了输入中文字符，VIM里出现无法识别的情况，出现了各种方块。
和locale有关。

之前在EC25E上移植TMUX，没成功，最后也是这个问题需要配置。

实际上Debian上支持locale，执行dpkg-reconfigure locales 也能配置，但是返回有报错，并且最终没有生效。
直接修改/etc/default/locale ，重启后也不行。

	apt-get remove --purge locales -y
	apt-get install locales -y

卸载重装解决问题。

alais
-----

给命令起别名

alias ls="ls --color"


USBIP
-----

A great feature

![](Usbip.png)

[How_to_setup_and_use_USB/IP](https://developer.ridgerun.com/wiki/index.php?title=How_to_setup_and_use_USB/IP)




other
----
