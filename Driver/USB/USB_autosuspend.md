USB_autosuspend
=====

翻译自

[https://lwn.net/Articles/373550/](https://lwn.net/Articles/373550/)

Linux kernel 很久以前就支持STR(Suspend to RAM)和STD(Suspend to Disk). Linux的Suspend机制很有意义，但是有些重大缺陷：设备Suspend后就无法工作了。降低功耗，同时保留设备处于active状态会是更优秀的功能。
这被成为 runtime power management。这一般是通过降低clock和关闭部分组件实现。

API
-----

The API for implementing USB autosuspend is based on drivers telling the core USB subsystem whenever a reason for not suspending a device arises or ceases to exist. The subsystem counts the reasons why a device must not be autosuspended; the core USB subsystem may then suspend a device whose counters have reached zero. "Counters" is not a typo: a USB device may consist of a multitude of interfaces, each of which may have its own driver.

The counters are manipulated with "get" and "put" functions which wake or suspend devices according to the state of the counters. They are provided in synchronous and asynchronous versions.

	usb_autopm_get_interface(struct usb_interface *);
	Increment the counter and guarantee the device has been resumed (may sleep)
	usb_autopm_put_interface(struct usb_interface *);
	Decrement the counter (may sleep)
	usb_autopm_get_interface_async(struct usb_interface *);
	Increment the counter, which will wake the device at a later time (safe in atomic contexts).
	usb_autopm_put_interface_async(struct usb_interface *);
	Decrement the counter (safe in atomic contexts)

The asynchronous versions were recently fixed in commit ccf5b801 for the 2.6.32 release; earlier kernels were buggy. Those stuck with an older kernel for some reason cannot use these functions.

For these manipulations of the counters to have any effect, a driver must tell the USB subsystem that it supports USB autosuspend. It does so by setting a flag in its usb_driver structure. For example, the kaweth driver includes this initialization:

	    static struct usb_driver kaweth_driver = {
	        /* ... */
	        .supports_autosuspend = 1,
	    };

The core USB subsystem guarantees drivers that for all its calls to methods of struct usb_driver, except for, of course, resume() and reset_resume(), the device in question has been resumed and won't be suspended while the call is in progress.

Sysfs
-----

Two sysfs attributes are exported pertaining to USB autosuspend for each device.

	/sys/$DEVICE/power/level
	On for inactive autosuspend, auto for active autosuspend
	/sys/$DEVICE/power/autosuspend

The delay between counters reaching zero and autosuspend in seconds.
The delay mentioned in this table serves a double function. Firstly, some devices have a large energy consumption when resuming; disks, for example, have to spin up. Suspending them for a very short time saves no energy. The delay is a heuristic to avoid such situations. Secondly some devices need time to process data even after the host has finished talking to them. So do not set this delay to zero unless you know what you are doing.



