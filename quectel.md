How to Use Quectel Modules
======

Detailed please take look at :

<a href="http://QuectelWB.github.io" target="_blank">Work in Quectel</a>



Links
-----
*[`Official Website`](https://www.quectel.com/ "Official Website")*

*[`Forums`](https://Forums.quectel.com/ "Forums")*

GobiNet Usb Staffs
-----

	
	GobiUSBNetProbe
			...
			usb_control_msg(
				interface_to_usbdev(pIntf),
				usb_sndctrlpipe(interface_to_usbdev(pIntf), 0),
				0x22, //USB_CDC_REQ_SET_CONTROL_LINE_STATE
				0x21, //USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE
				1, //active CDC DTR
				pIntf->cur_altsetting->desc.bInterfaceNumber,
				NULL, 0, 100);

pIntf->cur_altsetting->desc.bInterfaceNumber ---> 4

usbmon log:

	ffff8ff2d74da840 2154856978 C Co:2:005:0 0 13 >
	ffff8ff49068b780 2154857014 S Co:2:005:0 s 21 22 0001 0004 0000 0
	ffff8ff49068b780 2154857102 C Co:2:005:0 0 0



