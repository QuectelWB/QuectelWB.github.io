if test -z $1 ; then
	echo need a argument: down/up
exit
fi 

if [ "up" = $1  ] ; then
	# 新建一个网桥，名称为br0
	brctl addbr br0
	# 将网络设备enp0s10添加到网桥br0 
	ifconfig enp0s9 down
	brctl addif br0 enp0s9

	# 关闭生成树协议
	brctl stp br0 off

	ifconfig br0 192.168.1.1 netmask 255.255.255.0 promisc up
	ifconfig enp0s9 192.168.1.88 netmask 255.255.255.0 promisc up


	 # 使用命令tunctl添加虚拟网卡tap
	tunctl -t tap0 -u rlk

	ifconfig tap0 192.168.1.89 netmask 255.255.255.0 promisc up

	brctl addif br0 tap0

else
	ifconfig tap0 down
	brctl delif br0 tap0

	ifconfig enp0s9 down
	brctl delif br0 enp0s9
	ifconfig br0 down
	brctl delbr br0

	ifconfig enp0s9 192.168.1.88 netmask 255.255.255.0
fi
