USB共享网络
=====

LicheePi Zero 和 主机之间实现USB网

ECM
----


主机上

	root@m:~/lichee# lsusb -t
	/:  Bus 02.Port 1: Dev 1, Class=root_hub, Driver=xhci_hcd/4p, 5000M
	/:  Bus 01.Port 1: Dev 1, Class=root_hub, Driver=xhci_hcd/11p, 480M
	    |__ Port 4: Dev 50, If 3, Class=CDC Data, Driver=cdc_acm, 480M
	    |__ Port 4: Dev 50, If 1, Class=CDC Data, Driver=cdc_ether, 480M
	    |__ Port 4: Dev 50, If 2, Class=Communications, Driver=cdc_acm, 480M
	    |__ Port 4: Dev 50, If 0, Class=Communications, Driver=cdc_ether, 480M
	    |__ Port 5: Dev 3, If 0, Class=Video, Driver=uvcvideo, 480M
	    |__ Port 5: Dev 3, If 1, Class=Video, Driver=uvcvideo, 480M
	    |__ Port 6: Dev 47, If 0, Class=Wireless, Driver=btusb, 12M
	    |__ Port 6: Dev 47, If 1, Class=Wireless, Driver=btusb, 12M
	    |__ Port 8: Dev 5, If 0, Class=Vendor Specific Class, Driver=rtsx_usb, 480M
	root@m:~/lichee# lsusb
	Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
	Bus 001 Device 005: ID 0bda:0129 Realtek Semiconductor Corp. RTS5129 Card Reader Controller
	Bus 001 Device 047: ID 13d3:3474 IMC Networks Atheros AR3012 Bluetooth
	Bus 001 Device 003: ID 04f2:b483 Chicony Electronics Co., Ltd USB2.0 VGA UVC WebCam
	Bus 001 Device 050: ID 0525:a4aa Netchip Technology, Inc. Linux-USB CDC Composite Gadge (Ethernet and ACM)
	Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
	root@m:~/lichee# ifconfig usb0
	usb0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
		inet 192.168.2.1  netmask 255.255.255.0  broadcast 192.168.2.255
		ether 32:2f:e8:dd:d9:f4  txqueuelen 1000  (以太网)
		RX packets 7  bytes 476 (476.0 B)
		RX errors 0  dropped 0  overruns 0  frame 0
		TX packets 10  bytes 835 (835.0 B)
		TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

	[870793.520695] usb 1-4: new high-speed USB device number 50 using xhci_hcd
	[870793.541394] usb 1-4: New USB device found, idVendor=0525, idProduct=a4aa, bcdDevice= 4.10
	[870793.541397] usb 1-4: New USB device strings: Mfr=1, Product=2, SerialNumber=0
	[870793.541398] usb 1-4: Product: CDC Composite Gadget
	[870793.541399] usb 1-4: Manufacturer: Linux 4.10.15-licheepi-zero with musb-hdrc
	[870793.551046] cdc_ether 1-4:1.0 usb0: register 'cdc_ether' at usb-0000:00:14.0-4, CDC Ethernet Device, 32:2f:e8:dd:d9:f4
	[870794.341814] cdc_acm 1-4:1.2: ttyACM0: USB ACM device
	[870794.343432] usbcore: registered new interface driver cdc_acm
	[870794.343434] cdc_acm: USB Abstract Control Model driver for USB modems and ISDN adapters


在LicheePi Zero 上

	# ifconfig usb0
	usb0      Link encap:Ethernet  HWaddr C2:0B:08:9E:AE:BF
		  inet addr:192.168.2.100  Bcast:192.168.2.255  Mask:255.255.255.0
		  UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
		  RX packets:11 errors:0 dropped:0 overruns:0 frame:0
		  TX packets:7 errors:0 dropped:0 overruns:0 carrier:0
		  collisions:0 txqueuelen:1000
		  RX bytes:768 (768.0 B)  TX bytes:574 (574.0 B)

	# ping 192.168.2.1
	PING 192.168.2.1 (192.168.2.1): 56 data bytes
	64 bytes from 192.168.2.1: seq=0 ttl=64 time=0.833 ms
	64 bytes from 192.168.2.1: seq=1 ttl=64 time=0.404 ms
	64 bytes from 192.168.2.1: seq=2 ttl=64 time=0.294 ms
	64 bytes from 192.168.2.1: seq=3 ttl=64 time=0.391 ms
	64 bytes from 192.168.2.1: seq=4 ttl=64 time=0.399 ms
	^C
	--- 192.168.2.1 ping statistics ---
	5 packets transmitted, 5 packets received, 0% packet loss
	round-trip min/avg/max = 0.294/0.464/0.833 ms
	
	[    2.508579] g_cdc gadget: high-speed config #1: CDC Composite (ECM + ACM)


LicheePi 内核

drivers/usb/gadget/legacy/ether.c

	#define CDC_VENDOR_NUM          0x0525  /* NetChip */
	#define CDC_PRODUCT_NUM         0xa4a1  /* Linux-USB Ethernet Gadget */


	static struct usb_device_descriptor device_desc = { 
	    .bLength =      sizeof device_desc,
	    .bDescriptorType =  USB_DT_DEVICE,

	    .bcdUSB =       cpu_to_le16 (0x0200),

	    .bDeviceClass =     USB_CLASS_COMM,
	    .bDeviceSubClass =  0,  
	    .bDeviceProtocol =  0,  
	    /* .bMaxPacketSize0 = f(hardware) */

	    /* Vendor and product id defaults change according to what configs
	     * we support.  (As does bNumConfigurations.)  These values can
	     * also be overridden by module parameters.
	     */
	    .idVendor =     cpu_to_le16 (CDC_VENDOR_NUM),
	    .idProduct =        cpu_to_le16 (CDC_PRODUCT_NUM),
	    /* .bcdDevice = f(hardware) */
	    /* .iManufacturer = DYNAMIC */
	    /* .iProduct = DYNAMIC */
	    /* NO SERIAL NUMBER */
	    .bNumConfigurations =   1,  
	}; 




[hi3559平台增加USB网卡（RNDIS/Ethernet Gadget）功能](https://blog.csdn.net/zhenglie110/article/details/80223167/)

[USB内核配置](http://blog.chinaunix.net/uid-29958595-id-4844656.html)

[s5pv210 安卓的rndis驱动的usb网络共享的实现](https://blog.csdn.net/xiaoxiaozhu2010/article/details/52330616)


