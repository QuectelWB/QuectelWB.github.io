USB的标准请求
======

USB标准请求和usbmon验证


	struct usb_ctrlrequest {
		__u8 bRequestType;
		__u8 bRequest;
		__le16 wValue;
		__le16 wIndex;
		__le16 wLength;
	} __attribute__ ((packed));


usb 请求的结构

| 偏移量 |	域 |	长度（字节）|	值 |	描述 |
| ---- | ---- | ---- | ---- |
| 0 |	bmRequestType | 1 | 位图 | 请求特征：<br> D7：传输方向 <br> 0=主机至设备 <br> 1=设备至主机 <br> D6..5：种类 <br> 0=标准 <br> 1=类 <br> 2=厂商 <br> 3=保留 <br>  D4..0：接受者 <br> 0=设备 <br> 1=接口 <br> 2=端点  <br> 3=其他  <br> 4..31 保留  |
| 1 |	bRequest |	1 |	值 |	命令类型编码值 |
| 2 |	wValue	| 2 |	值 |	根据不同的命令，含义也不同 |
|4 |	wIndex	| 2 |	索引或偏移 |	根据不同的命令，含义也不同，主要用于传送索引或偏移 |
|6 |	wLength	| 2 |	如有数据传送阶段，此为数据字节数。 |


11 种标准请求，其中和远程唤醒有关的Clear_Feature 和 Set_Feature

| 命令	| bmRequestType | bRequest | wValue | wIndex | wLength | Data |
| ---- | ----- | ---- | ---- | ---- | ---- | ---- | ---- |
| clear_Feature | 00000000B <br> 00000001B <br> 00000010B | CLEAR_FEATURE | 特性选择符 | 零 | 接口号  | 端点号 | 零 | 无 |
| set_Feature | 00000000B <br> 00000001B <br> 00000010B | SET_FEATURE | 特性选择符<br>（1 for device, 0 for endpoint） | 零 | 接口号  | 端点号 | 零 | 无 |

bmRequestType

| bRequest |Value |
| ---- | ---- |
| GET_STATUS |  0 |
| CLEAR_FEATURE | 1 |
| 为将来保留 | 2 |
| SET_FEATURE | 3 |
| 为将来保留 | 4 |
| SET_ADDRESS | 5 |
| GET_DESCRIPTOR | 6 |
| SET_DESCRIPTOR | 7 |
| GET_CONFIGURATION | 8 |
| SET_CONFIGURATION | 9 |
| GET_INTERFACE | 10 |
| SET_INTERFACE | 11 |
| SYNCH_FRAME | 12 |

