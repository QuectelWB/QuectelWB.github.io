---
title: OPENWRT编译之树莓派4B
date: 2019-11-24
categories: Linux
tags: rpi
---

# 环境配置说明

- 适用硬件：Raspberry Pi 4B
- 编译系统：Debian For WSL
- 参考借鉴：[参数配置](https://mlapp.cn/374.html) | [LuCI配置](https://www.right.com.cn/forum/thread-344825-1-1.html) | [网卡设置](https://www.right.com.cn/forum/thread-406062-1-1.html)

```bash
# 安装编译工具
sudo apt-get update
sudo apt-get install build-essential asciidoc binutils bzip2 \
gawk gettext git libncurses5-dev libz-dev patch unzip zlib1g-dev \
lib32gcc1 libc6-dev-i386 subversion flex uglifyjs libssl-dev upx \
gcc-multilib p7zip p7zip-full msmtp texinfo libglib2.0-dev xmlto \
git-core qemu-utils libelf-dev autoconf automake libtool autopoint \
curl wget device-tree-compiler rsync

```

# 获取编译源码

> 1. 注意：不要使用root用户编译，最好使用梯子来加速源码的下载速度
> 2. 编译完成后把bin/targets/brcm27xx/bcm2711/openwrt-bcm27xx-bcm2711-rpi-4-ext4-factory.img.gz解压后的img文件刷入SD卡中即可
> 3. 可选lean版魔改源码替换官方源码：https://github.com/coolsnowwolf/lede

```bash
# 设置代理来加速源码下载，没有代理可跳过或根据需求设置
# export all_proxy="127.0.0.1:7890"

# 获取openwrt官方源码
mkdir openwrt
cd openwrt/
git clone https://git.openwrt.org/openwrt/openwrt.git ./

# 以后每次编译前建议执行以下三行命令更新源码
git pull
./scripts/feeds update -a
./scripts/feeds install -a

make defconfig		# 测试编译环境
make menuconfig		# 进入固件配置界面
make download -j8 V=s	# 下载所需源码，请尽量使用梯子
make -j1 V=s		# 首次编译推荐用单线程

# 再次编译前建议使用make clean清理
make clean	# 清除bin目录
make dirclean	# 清除bin目录和交叉编译工具及工具链目录
make distclean	# 清除所有相关的东西，包括下载的软件包，配置文件，feed内容等

```


# 可选内核配置

```bash
# 额外配置内核参数，一般不需要配置
# 只能包含到内核而不能作为模块，因为编译后的模块不会添加到固件内
make kernel_menuconfig	# 进入内核配置界面

# 修改的内核参数会保存到openwrt/target/linux/bcm27xx/bcm2711/config-5.4
# 和openwrt/target/linux/generic/config-5.4合成最终内核配置文件
# openwrt/build_dir/target-aarch64_cortex-a72_musllinux-bcm27xx_bcm2711/linux-5.4.42/.config

```


# 固件编译配置

1. 简单的make menuconfig参数配置，除必选配置外的其他项可根据需求自行选择

2. 基础配置

```bash
# 必选配置
Target System -> Broadcom BCM27xx
Subtarget -> BCM2711 boards (64 bit)
Target Profile -> Raspberry Pi 4B

# 镜像参数
Target Images -> ext4		# ext4格式的固件可方便地调整分区大小
Target Images -> squashfs	# squashfs格式的固件可恢复出厂设置
Target Images -> Kernel partition size = 64		# boot分区大小为64M
Target Images -> Root filesystem partition size = 512	# root分区大小为512M

# 可选工具
Base system -> block-mount	# 在LuCI界面添加<挂载点>菜单
Base system -> blockd		# 自动挂载设备
Base system -> wireless-tools	# 无线扩展工具
Administration -> htop		# 添加htop命令
Firmware -> xxx			# 选择你需要的网卡固件，默认即可

```

3. 内核模块

```bash
# 文件系统
Kernel modules -> Filesystems -> kmod-fs-ext4
Kernel modules -> Filesystems -> kmod-fs-ntfs
Kernel modules -> Filesystems -> kmod-fs-squashfs
Kernel modules -> Filesystems -> kmod-fs-vfat
Kernel modules -> Filesystems -> kmod-fuse

# 网卡支持
Kernel modules -> Network Devices -> kmod-xxx	# 有线网卡支持，跟以下几项可根据需求选择性添加
Kernel modules -> Wireless Drivers -> kmod-rt2800-usb			# 添加Ralink RT5370芯片的USB无线网卡驱动
Kernel modules -> USB Support -> kmod-usb-net -> kmod-usb-net-sr9700	# 添加USB2.0的有线网卡SR9700芯片支持
Kernel modules -> USB Support -> kmod-usb-net -> kmod-usb-net-rtl8152	# 添加USB2/3的有线网卡RTL8152/3芯片支持
Kernel modules -> USB Support -> kmod-usb-net -> kmod-usb-net-asix	# 添加支持亚信的有线网卡支持
Kernel modules -> USB Support -> kmod-usb-net -> kmod-usb-net-asix-ax88179  # 添加USB3.0的有线网卡芯片AX88179的驱动

# USB支持
Kernel modules -> USB Support -> kmod-usb-core		# 启用USB支持
Kernel modules -> USB Support -> kmod-usb-hid		# USB键鼠支持
Kernel modules -> USB Support -> kmod-usb-ohci		# 添加OHCI支持
Kernel modules -> USB Support -> kmod-usb-uhci		# 添加UHCI支持
Kernel modules -> USB Support -> kmod-usb-storage	# 启用USB存储
Kernel modules -> USB Support -> kmod-usb-storage-extras
Kernel modules -> USB Support -> kmod-usb-usb2		# 开启USB2支持
Kernel modules -> USB Support -> kmod-usb-usb3		# 开启USB3支持

```

4. LuCI配置 

```bash
# LuCI设置
LuCI -> Collections -> luci				# 开启luci
LuCI -> Modules -> Translations	-> Chinese(zh-cn)	# 中文支持
LuCI -> Themes -> luci-theme-material			# 添加主题

# LuCI应用
LuCI -> Applications -> luci-app-aria2			# 下载工具
LuCI -> Applications -> luci-app-firewall		# 防 火 墙
LuCI -> Applications -> luci-app-hd-idle		# 硬盘休眠
LuCI -> Applications -> luci-app-opkg			# 软 件 包
LuCI -> Applications -> luci-app-qos			# 服务质量
LuCI -> Applications -> luci-app-samba4			# 网络共享
LuCI -> Applications -> luci-app-frpc			# 内网穿透
LuCI -> Applications -> luci-app-shadowsocks-libev	# 翻墙软件
LuCI -> Applications -> luci-app-upnp			# UPnP服务
LuCI -> Applications -> luci-app-wol			# 网络唤醒
......

```

5. 其他工具

```bash
Network -> Download Manager -> ariang	# Aria2管理页面
Network -> File Transfer -> Aria2 Configuration -> ***	# 选择Aria2支持的功能
Network -> File Transfer -> curl	# 添加curl命令
Network -> File Transfer -> wget	# 添加wget命令
Utilities -> Compression -> bsdtar	# tar打包工具
Utilities -> Compression -> gzip	# GZ 压缩套件
Utilities -> Compression -> xz-utils	# XZ 压缩套件
Utilities -> Compression -> unzip	# zip解压工具
Utilities -> Compression -> zip		# zip压缩工具
Utilities -> Disc -> fdisk		# 磁盘分区工具
Utilities -> Disc -> lsblk		# 磁盘查看工具
Utilities -> Editors -> vim		# vim编辑器
Utilities -> Filesystem -> ntfs-3g	# NTFS读写支持
Utilities -> Filesystem -> resize2fs	# 分区大小调整
Utilities -> Terminal -> screen		# 添加screen
Utilities -> pciutils			# 添加lspci命令
Utilities -> usbutils			# 添加lsusb命令

```

6. IPv6支持

```bash
Global build settings -> Enable IPv6 support in packages	# 启用IPv6项
Network -> odhcp6c						# IPv6客户端
Network -> odhcpd-ipv6only					# IPv6服务端
Network -> Firewall -> ip6tables				# IPv6防火墙
LuCI -> Protocols -> luci-proto-ipv6				# WebUI支持

```


# 手动配置网卡

1. 用网线连接自己的电脑和树莓派，LEDE默认的IP为静态 192.168.1.1，可以将电脑网卡设置为静态IP：192.168.1.2 来访问树莓派上的LEDE管理界面。

2. 设置2.4G无线：网络 -> 无线 选项卡中点修改，基本设置中设置为Legacy模式，频宽2.4GHz和信道自选（切勿使用自动信道和自动频宽），高级设置中国家代码AU。接口配置中模式：接入点AP，网络：lan，然后设置无线安全加密WPA2-PSK和密码等，其余默认即可。

3. 设置5G无线：网络 -> 无线 选项卡中点修改，基本设置中设置为AC模式，只能使用36信道和频宽为20Mhz或者40Mhz才能用作AP（切勿使用自动信道和自动频宽），高级设置中国家代码AU。接口配置中模式：接入点AP，网络：lan，然后设置无线安全加密WPA2-PSK和密码等，其余默认即可。

4. 设置WAN口 网络 -> 接口 选项卡中添加一个新接口命名为"wan"，协议根据自己的网络情况自行选择(我的是DHCP客户端)，在 物理设置 中单选接口为eth0，先保存但别应用。设置LAN口 网络 -> 接口 选项卡中编辑lan网卡的物理设置，在无线网络和自定义接口上打上钩填上"eth0.1"， 并取消原本eth0前的钩后保存。


# 自动配置网卡

> 在openwrt目录下新建一个名为files的文件夹，openwrt在编译的时候，会把files文件夹里的文件编译到固件的根目录。
> 在files/etc/config/中新建两个文件：network，wireless内容如下用来分别配置接口和无线


```bash
# openwrt/files/etc/config/network

config interface 'loopback'
	option ifname 'lo'
	option proto 'static'
	option ipaddr '127.0.0.1'
	option netmask '255.0.0.0'

config globals 'globals'
	option ula_prefix 'fd38:13ae:ceeb::/48'

config interface 'lan'
	option type 'bridge'
	option proto 'static'
	option ipaddr '192.168.1.1'
	option netmask '255.255.255.0'
	option ip6assign '60'
	option ifname 'eth0.1'
	option _orig_ifname 'eth0 wlan0'
	option _orig_bridge 'true'

config interface 'wan'
	option ifname 'eth0'
	option proto 'dhcp'
	option _orig_ifname 'erspan0'
	option _orig_bridge 'false'

```

```bash
# openwrt/files/etc/config/wireless

config wifi-device 'radio0'
	option type 'mac80211'
	option channel '36'
	option hwmode '11a'
	option path 'platform/soc/fe300000.mmcnr/mmc_host/mmc1/mmc1:0001/mmc1:0001:1'
	option htmode 'VHT40'

config wifi-iface 'default_radio0'
	option device 'radio0'
	option mode 'ap'
	option encryption 'none'
	option ssid 'RPI4'
	option network 'lan'

```


# 其他实用技巧

1. 系统 -> LED配置中：LED0是绿色灯，LED1是红色灯，可以用来当无线收发的指示灯
2. 使用：`cat /sys/class/thermal/thermal_zone0/temp` 查看CPU温度
3. 在Samba中使用root用户除了执行smbpasswd -a root添加用户外，还需要注释模板中的：`#invalid users = root`
4. 使用Win10 WSL环境编译的，编译前建议先将Win10系统变量剔除，否则可能报错：`export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin`
5. 单核编译大概需要4个小时，中间可能会有几次错误，有的错误可跳过对后续编译没有影响
6. 在OpenWRT的 `.config` 文件中内核的选项都是形如 `CONFIG_KERNEL_XXX` 。自己手动添加内核选项时不要忘了在中间添加 `_KERNEL_` 前缀。
7. Goproxy代理失败报错的解决方法：`export GO111MODULE=on` 和 `export GOPROXY=https://goproxy.cn`

```bash
go: github.com/armon/go-socks5@v0.0.0-20160902184237-e75332964ef5: Get "https://proxy.golang.org/github.com/armon/go-socks5/@v/v0.0.0-20160902184237-e75332964ef5.mod": dial tcp 172.217.27.145:443: connect: connection refused

```


