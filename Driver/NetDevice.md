
Net_Interface
=======


netif_carrier_ok
-----

网络链路是断开还是连接

	#include <linux/netdevice.h>
	static inline bool netif_carrier_ok(const struct net_device *dev)
		...
		!test_bit(__LINK_STATE_NOCARRIER, &dev->state);
		...


网链接断开的时候，会将LinkSts清位；重新链接，则硬件自动将此位置位。

在网卡驱动程序中通常需要实现suspend和resume函数来支持设备的挂起和恢复操作


	netif_device_attach
	将net_device的state中的__LINK_STATE_PRESENT置位。同时开启发送队列
	netif_device_detach
	将net_device的state中的__LINK_STATE_PRESENT清位。同时关闭发送队列


netif_carrier_on
--------

告诉内核子系统网络链接完整。




