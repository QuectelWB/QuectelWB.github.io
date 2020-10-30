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


后来重启后，一切恢复了，中文又再次无法


export LC_ALL=zh_CN.UTF-8


alais
-----

给命令起别名

alias ls="ls --color"


UsbIp
-----

USB over IP , A great feature

![](Usbip.png)

[How_to_setup_and_use_USB/IP](https://developer.ridgerun.com/wiki/index.php?title=How_to_setup_and_use_USB/IP)

```Example 

q@q-OptiPlex-7070:~$ /usr/lib/linux-tools/5.4.0-52-generic/usbip list -l
usbip: error: failed to open /usr/share/hwdata//usb.ids
 - busid 1-12 (413c:2113)
   unknown vendor : unknown product (413c:2113)

 - busid 1-5.4 (1976:4082)
   unknown vendor : unknown product (1976:4082)

q@q-OptiPlex-7070:~$ /usr/lib/linux-tools/5.4.0-52-generic/usbip list -r 10.66.125.234
usbip: error: failed to open /usr/share/hwdata//usb.ids
Exportable USB devices
======================
 - 10.66.125.234
        1-4: unknown vendor : unknown product (2c7c:0125)
           : /sys/devices/pci0000:00/0000:00:14.0/usb1/1-4
           : unknown class / unknown subclass / unknown protocol (ef/02/01)

q@q-OptiPlex-7070:~$ sudo /usr/lib/linux-tools/5.4.0-52-generic/usbip attach -r 10.66.125.234 -b 1-4

q@q-OptiPlex-7070:~$ lsusb
Bus 004 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 003 Device 002: ID 2c7c:0125 Quectel Wireless Solutions Co., Ltd. EC25 LTE modem
Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 004: ID 1976:4082 Chipsbrand Microelectronics (HK) Co., Ltd.
Bus 001 Device 002: ID 1a40:0101 Terminus Technology Inc. Hub
Bus 001 Device 005: ID 413c:2113 Dell Computer Corp. Dell KB216 Wired Keyboard
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub


[711228.658191] vhci_hcd vhci_hcd.0: USB/IP Virtual Host Controller
[711228.658193] vhci_hcd vhci_hcd.0: new USB bus registered, assigned bus number 3
[711228.658197] vhci_hcd: created sysfs vhci_hcd.0
[711228.658219] usb usb3: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 5.04
[711228.658220] usb usb3: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[711228.658220] usb usb3: Product: USB/IP Virtual Host Controller
[711228.658221] usb usb3: Manufacturer: Linux 5.4.0-48-generic vhci_hcd
[711228.658222] usb usb3: SerialNumber: vhci_hcd.0
[711228.658359] hub 3-0:1.0: USB hub found
[711228.658363] hub 3-0:1.0: 8 ports detected
[711228.658459] vhci_hcd vhci_hcd.0: USB/IP Virtual Host Controller
[711228.658460] vhci_hcd vhci_hcd.0: new USB bus registered, assigned bus number 4
[711228.658477] usb usb4: We don't know the algorithms for LPM for this host, disabling LPM.
[711228.658491] usb usb4: New USB device found, idVendor=1d6b, idProduct=0003, bcdDevice= 5.04
[711228.658491] usb usb4: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[711228.658492] usb usb4: Product: USB/IP Virtual Host Controller
[711228.658493] usb usb4: Manufacturer: Linux 5.4.0-48-generic vhci_hcd
[711228.658493] usb usb4: SerialNumber: vhci_hcd.0
[711228.658595] hub 4-0:1.0: USB hub found
[711228.658599] hub 4-0:1.0: 8 ports detected
[711574.023109] usbcore: registered new device driver usbip-host
[711696.394509] vhci_hcd vhci_hcd.0: pdev(0) rhport(0) sockfd(3)
[711696.394510] vhci_hcd vhci_hcd.0: devid(65602) speed(3) speed_str(high-speed)
[711696.629478] usb 3-1: new high-speed USB device number 2 using vhci_hcd
[711696.769483] usb 3-1: SetAddress Request (2) to port 0
[711696.837940] usb 3-1: New USB device found, idVendor=2c7c, idProduct=0125, bcdDevice= 3.18
[711696.837947] usb 3-1: New USB device strings: Mfr=1, Product=2, SerialNumber=0
[711696.837950] usb 3-1: Product: Android
[711696.837953] usb 3-1: Manufacturer: Android
[711696.962058] usbcore: registered new interface driver usbserial_generic
[711696.962063] usbserial: USB Serial support registered for generic
[711697.126640] usbcore: registered new interface driver option
[711697.126647] usbserial: USB Serial support registered for GSM modem (1-port)
[711697.126694] option 3-1:1.0: GSM modem (1-port) converter detected
[711697.126788] usb 3-1: GSM modem (1-port) converter now attached to ttyUSB0
[711697.126810] option 3-1:1.1: GSM modem (1-port) converter detected
[711697.126869] usb 3-1: GSM modem (1-port) converter now attached to ttyUSB1
[711697.126889] option 3-1:1.2: GSM modem (1-port) converter detected
[711697.126917] usb 3-1: GSM modem (1-port) converter now attached to ttyUSB2
[711697.126935] option 3-1:1.3: GSM modem (1-port) converter detected
[711697.126961] usb 3-1: GSM modem (1-port) converter now attached to ttyUSB3
[711697.126990] option 3-1:1.5: GSM modem (1-port) converter detected
[711697.127014] option 3-1:1.6: GSM modem (1-port) converter detected
[711697.127035] option 3-1:1.7: GSM modem (1-port) converter detected
[711697.135638] usbcore: registered new interface driver cdc_wdm
[711697.169606] qmi_wwan 3-1:1.4: cdc-wdm1: USB WDM device
[711697.174201] qmi_wwan 3-1:1.4 wwan0: register 'qmi_wwan' at usb-vhci_hcd.0-1, WWAN/QMI device, 2e:07:fd:3d:7e:a5
[711697.174241] usbcore: registered new interface driver qmi_wwan
[711697.351729] mc: Linux media interface: v0.10
[711697.413620] usbcore: registered new interface driver snd-usb-audio
[711699.152259] vhci_hcd: unlink->seqnum 51
[711699.152260] vhci_hcd: urb->status -104
[711699.264750] vhci_hcd: unlink->seqnum 62
[711699.264752] vhci_hcd: urb->status -104


```

other
----
