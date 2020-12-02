title: 如何设置风扇
---

这篇文档介绍如何在Ubuntu下设置风扇。

## 通过修改配置文件修改

### 准备工作
* Ubuntu版本必须为`V20190319`或更新版本

对于Ubuntu `V20190319`风扇默认是使能的。

风扇有5种工作模式：
* `off`: 风扇关闭。
* `low`: 风扇工作在低速模式。
* `mid`: 风扇工作在中等速度模式。
* `high`: 风扇工作在高速模式。
* `auto`: 风扇工作在自动调节速度模式，根据温度自动调节速度，这个是默认的工作模式。

### 设置工作模式

你可以通过编辑文件`/boot/env.txt`来设置风扇的工作模式。

* 设置风扇低速模式

编辑`/boot/env.txt`设置`fan_mode=low`。

* 设置风扇中等速度模式

编辑`/boot/env.txt`设置`fan_mode=mid`。

* 设置风扇高速模式

编辑`/boot/env.txt`设置`fan_mode=high`。

* 设置风扇自动调节速度模式

编辑`/boot/env.txt`设置`fan_mode=auto`。

* 关闭风扇

编辑`/boot/env.txt`设置`fan_mode=off`。

编辑完后记得保存文件并重启板子。

```
khadas@Khadas:~$ sync
khadas@Khadas:~$ sudo reboot
```


## 通过风扇应用设置

* Step1: 打开风扇应用

你可以在系统的应用列表中找到`FAN Setting`

![FAN Setting](/images/vim1/gnome_application_fan.png)

打开这个应用

* Step2: 选择风扇工作模式

![Fan Setting](/images/vim1/gnome_fan_setting.png)

可以选择你需要的工作模式,默认是`auto`.

* Step3: 保存

![Fan save](/images/vim1/gnome_fan_save.png)

可以将你的选择保存为默认选项

![Fan PSK](/images/vim1/gnome_fan_psk.png)

密码就是你的用户密码

