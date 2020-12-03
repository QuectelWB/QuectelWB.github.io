PowerManagement
======


USB remote wakeup
------

[usb: hub: change CLEAR_FEATURE to SET_FEATURE](https://patchwork.kernel.org/project/linux-mediatek/patch/1471577846-15816-1-git-send-email-yonglong.wu@mediatek.com/)

In USB20 specification, describes in chapter 9.4.5: The Remote Wakeup
field can be modified by the SetFeature() and ClearFeature() requests
using the DEVICE_REMOTE_WAKEUP feature selector.

In USB30 specification, also describes in chapter 9.4.5: The Function
Remote Wakeup field can be modified by the SetFeature() requests
using the FUNCTION_SUSPEND feature selector. In chapter 9.4.9 Set
Feature reference, it describes Function Remote Wake Enabled/Disabled
at suspend options by SET_FEATURE.

In USB30 specification only mentioned SetFeature(), so we need use
SET_FEATURE replace CLEAR_FEATURE to disable USB30 function remote
wakeup in suspend options.


	diff --git a/drivers/usb/core/hub.c b/drivers/usb/core/hub.c
	index bee1351..a6f5095 100644
	--- a/drivers/usb/core/hub.c
	+++ b/drivers/usb/core/hub.c
	@@ -3111,7 +3111,7 @@  static int usb_disable_remote_wakeup(struct usb_device *udev)
					USB_CTRL_SET_TIMEOUT);
		else
			return usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
	-				USB_REQ_CLEAR_FEATURE, USB_RECIP_INTERFACE,
	+				USB_REQ_SET_FEATURE, USB_RECIP_INTERFACE,
					USB_INTRF_FUNC_SUSPEND,	0, NULL, 0,
					USB_CTRL_SET_TIMEOUT);
	 }



> Autosuspend

指定时间内没有收到数据

> RemoteWakeup

Device发送给Host的resume信号

主控如何开启远程唤醒支持
-------

Host 进休眠之前对remotewakeup setFeature，唤醒后clear Feature。

Set_Feature
	
Clear_Feature
	
清除或禁用特定功能

| bmRequestType | bRequest | wValue | wIndex | wLength | Data |
| ---- |     ---- | ---- | ---- | ---- | ---- |
| 00000000B <br>   00000001B <br> 00000010B | CLEAR_FEATURE | Feature <br> Seletor | Zero <br> Interface <br> Endpoint | Zero | None |









:)
