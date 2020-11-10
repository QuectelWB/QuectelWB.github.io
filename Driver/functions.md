Driver_Interface
=======


netif_carrier_ok
-----

网络链路是断开还是连接

	#include <linux/netdevice.h>
	static inline bool netif_carrier_ok(const struct net_device *dev)


!test_bit(__LINK_STATE_NOCARRIER, &dev->state);


