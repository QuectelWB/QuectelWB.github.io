SuspendResume
========



ACPI ----> S3 state.

不同级别的低功耗状态，包括CPUdile、Standoff、Suspend To RAM、Suspend to Disk、Power Off。




End
----

每次想起休眠唤醒，我都会想起睡美人的故事。

当公主触发了女巫的设定，即被针刺到后，就已经启动了睡眠设定了。睡眠不是立即让整个城堡里的所有动植同时瞬间睡眠的，而是从公主所在的地方开始，按照距离顺序休眠的。当王子吻上了睡美人后，城堡里的所有设备开始苏醒。最早醒的人，按照童话里的逻辑，应该也是公主，然后才是她周围的动植物。

睡美人的故事和Linux系统的休眠唤醒之间有相同的地方和不同的地方：

相同的地方

- 苏醒的人根本不知道他睡着了。进程和设备也不知道自己睡眠了。
- 睡眠的是有顺序的。设备通过链表
- 进入睡眠和唤醒需要人为触发

不同的地方

- 童话故事里的睡眠按照距离顺序进行，Linux Kernel里的设备和各种子系统的休眠，是按照Linux 设备的Suspend有关的4个链表进行的
- 无法解释 冻结进程，保存上下文的概念。<- 最后一个CPU或者是一个dsp或者mcpu完成的。故事里没有











[ArchLinux:Suspend and Hibernate](https://wiki.archlinux.org/index.php/Power_management/Suspend_and_hibernate)







