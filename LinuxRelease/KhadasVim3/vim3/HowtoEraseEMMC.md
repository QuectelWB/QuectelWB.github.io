title: 如何擦除eMMC存储器
---

有四种方式可以擦除VIMs板载eMMC存储器，如下：
* 按键模式
* 串口模式
* 中断模式
* 命令行模式

**注意：由于VIM1、VIM2和VIM3操作方式基本上是一样的，所以本文档以VIM1为例进行说明。**

### 按键模式(确保U-boot正常运行)
所有固件都只支持eMMC擦除，请按如下步骤擦除eMMC：

1. 给VIMs上电
2. 同时按住`Power`和 `Function`按键不松手
3. 短按 ‘Reset’按键
4. 执行上述步骤后U-boot会自动擦除eMMC，大概10S左右
5. 当eMMC数据擦除后，显示器会显示黑屏

### 串口模式(针对开发者)
1. 参考这里([VIM1](/vim3/SetupSerialTool.html)/[VIM2](/vim2/SetupSerialTool.html)/[VIM3](/vim3/SetupSerialTool.html))设置串口
2. 确保串口线连接正确以及串口软件正确配置
3. 在VIMs上电时按住任意键会进入U-boot命令行模式
4. U-boot命令行执行`store init 3`会擦除整个eMMC
5. 执行`reboot` 或按 `Reset`键重启
6. 参考如下:
```
kvim# store init 3
emmc/sd response timeout, cmd8, status=0x1ff2800
emmc/sd response timeout, cmd55, status=0x1ff2800
[mmc_startup] mmc refix success
[mmc_init] mmc init success
switch to partitions #0, OK
mmc1(part 0) is current device
Device: SDIO Port C
Manufacturer ID: 15
OEM: 100
Name: 8WPD3 
Tran Speed: 52000000
Rd Block Len: 512
MMC version 5.0
High Capacity: Yes
Capacity: 7.3 GiB
mmc clock: 40000000
Bus Width: 8-bit DDR
[store]amlmmc erase 1emmckey_is_protected : protect
start = 0,end = 57343


Caution! Your devices Erase group is 0x400
The erase range would be change to 0x36000~0xe8ffff

start = 221184,end = 15269886
Vim# reboot
```
**注意:**
如果擦除eMMC成功，在重启后可以在串口看到如下打印信息：
```
GXL:BL1:9ac50e:a1974b;FEAT:ADFC318C;POC:3;RCY:0;EMMC:0;READ:0;CHK:AA;SD:800;USB:8;
```

### 中断模式
这种方法适用于所有Amlogic产品。

1. 通过USB-C([VIM1](/vim3/UpgradeViaUSBCable.html)/[VIM2](/vim2/UpgradeViaUSBCable.html)/[VIM3](/vim3/UpgradeViaUSBCable.html)) 或TF卡([VIM1](/vim3/UpgradeViaTFBurningCard.html)/[VIM2](/vim2/UpgradeViaTFBurningCard.html)/[VIM3](/vim3/UpgradeViaTFBurningCard.html))升级固件.
2. 中断升级过程(建议进度条超过15%后中断), 例如, 拔掉USB数据线或TF卡
3. 重新上电，你会发现eMMC被擦除

### 命令行模式
这中方式适用于安装linux的设备。

1. 上电并进入到linux命令行# 如何擦除eMMC存储器
2. 打开终端使用`dd`命令清除U-boot分区
```
root@Khadas:~# dd if=/dev/zero of=/dev/bootloader
dd: writing to '/dev/bootloader': No space left on device
8193+0 records in
8192+0 records out
4194304 bytes (4.2 MB, 4.0 MiB) copied, 1.1226 s, 3.7 MB/s
root@Khadas:~# reboot
```
