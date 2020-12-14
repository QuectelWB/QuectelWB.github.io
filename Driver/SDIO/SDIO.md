SDIO
=====

SDIO SD卡标准的，外设接口


|  属性类型   | MMC卡  | SD卡 | SDIO卡 |
|  ----  | ----  | --- | --- |
| 引脚数量  | 7 | 9  | 9 |
| 宽度  | 24mm | 24mm | 24mm |
| 长度  | 32mm | 32mm | 32+mm |
| 厚度  | 1.4mm | 2.1mm | 2.1mm |
| 1位传输模式 | Y | Y | Y |
| 4位传输模式 | N | 可选 | 可选 |
| SPI 传输 | 可选 | 支持 | 支持 |
| 最高SPI传输速率 | 20Mbit/s | 25Mbit/s | 25Mbit/s |
| 最高传输率 | 20Mbit/s | 100Mbit/s | 100Mbit/s |
| 时钟频率 | 0-20MHz | 0-25MHz | 0-25MHz |

通常用SDIO的设备		
	
	Wi-Fi card （无线网络卡）
	CMOS sensor card （照相模块）
	GPS card
	GSM/GPRS modem card
	Bluetooth card
	Radio/TV card

SD 传输模式有以下 3 种：

- SPI mode
- 1-bit mode 
- 4-bit mode

SDIO 同样也支持以上 3 种传输模式。
依据 SD 标准，所有的 SD（记忆卡）与 SDIO（外围）都必须支持 SPI mode，因此 SPI mode 是「required」。此外，早期的 MMC 卡（使用 SPI 传输）也能接到 SD 插糟（SD slot），并且使用 SPI mode 或 1-bit mode 来读取。




MMC 协议
------

[codingbelief eMMC 总线协议](https://linux.codingbelief.com/zh/storage/flash_memory/emmc/emmc_bus_protocol.html)

![](multi_block_read.png)

![](multi_block_write.png)











