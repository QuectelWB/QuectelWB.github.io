Skeleton
=========

	m@m:~/Linux_Stduy/USB/test2$ make
	make -C /lib/modules/5.4.0-26-generic/build M=/home/m/Linux_Stduy/USB/test2 modules
	make[1]: 进入目录/usr/src/linux-headers-5.4.0-26-generic
	  Building modules, stage 2.
	  MODPOST 1 modules
	make[1]: 离开目录/usr/src/linux-headers-5.4.0-26-generic

	insmod skeleton

	[46296.361263] usbcore: registered new interface driver skeleton

	m@m:~/Linux_Stduy/USB/test2$ cd /sys/bus/usb/drivers/
	ath3k/             cdc_ether/         ftdi_sio/          hub/               qmi_wwan_q/        skeleton/          usb/               usbserial_generic/
	btusb/             cdc_wdm/           GobiNet/           option/            rtsx_usb/          snd-usb-audio/     usbfs/             uvcvideo/

	m@m:/sys/bus/usb/drivers/skeleton$ ls
	bind  module  new_id  remove_id  uevent  unbind


