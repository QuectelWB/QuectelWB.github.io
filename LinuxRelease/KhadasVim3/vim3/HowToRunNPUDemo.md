title: 如何在VIM3上面运行 NPU Demo
---

# 获取NPU Demo

NPU Demo 默认并没有安装在板子上. 需要先从gitlab自行下载

仓库在gitlab上的地址为:[https://gitlab.com/khadas/aml_npu_demo_binaries](https://gitlab.com/khadas/aml_npu_demo_binaries)

通过`git`命令中clone到板子上

```shell
$ cd {workspace}
$ git clone https://gitlab.com/khadas/aml_npu_demo_binaries
```

或者直接下载压缩包,然后解压到板子上


NPU Demo 一共有三个目录:

```
detect_demo: 摄像头动态识别的yolo系列模型合集
detect_demo_picture: 识别图片的yolo系列模型合集
inceptionv3: 识别图片的inception模型
```

# inception模型识别图片

1. inception模型不需要安装任何库到系统中.进入inceptionv3目录

```shell
$ cd {workspace}/aml_npu_demo_binaries/inceptionv3
$ ls
dog_299x299.jpg  goldfish_299x299.jpg  imagenet_slim_labels.txt  VIM3  VIM3L
```

`imagenet_slim_labels.txt`为label文件,识别出来结果以后可以在这个文件里查询结果对应的label.

2. 如果你的板子是VIM3,进入`VIM3`目录,是VIM3L则进入`VIM3L`目录.这里以VIM3为例

```shell
$ cd {workspace}/aml_npu_demo_binaries/inceptionv3/VIM3
$ inceptionv3  inception_v3.nb  run.sh
```

3. 运行`run.sh`

```shell
$ cd {workspace}/aml_npu_demo_binaries/inceptionv3/VIM3
$ ./run.sh
Create Neural Network: 59ms or 59022us
Verify...
Verify Graph: 0ms or 739us
Start run graph [1] times...
Run the 1 time: 20.00ms or 20497.00us
vxProcessGraph execution time:
Total   20.00ms or 20540.00us
Average 20.54ms or 20540.00us
 --- Top5 ---
  2: 0.833984
795: 0.009102
974: 0.003592
408: 0.002207
393: 0.002111
```

通过查询`imagenet_slim_labels.txt`得到结果是金鱼,也是就识别正确


4. 识别其他图片

```shell
$ cd {workspace}/aml_npu_demo_binaries/inceptionv3/VIM3
$ ./inceptionv3 inception_v3.nb path/to/picture
```

**note**:图片的尺寸要与模型的尺寸对应,因此这里,inceptionv3模型的输入是299x299x3,传入识别的图片也必须是299x299

# yolo系列模型

yolo系列模型的应用分成了摄像头动态识别和图片识别两个部分.

## 安装与卸载库

yolo系列的模型需要将库安装到系统中.无论是使用摄像头动态识别还是识别图片,共用了同一套库.

进入`detect_demo_picture`

```shell
$ cd {workspace}/aml_npu_demo_binaries/detect_demo_picture
```

安装

```shell
$ sudo ./INSTALL
```

卸载

```shell
$ sudo ./UNINSTALL
```

## `type`参数说明

`type`参数无论是使用摄像头动态识别,还是识别图片,都是必须选择的一个输入参数,这个参数主要是用于指定运行的yolo系列模型.

```
0 : yoloface模型
1 : yolov2模型
2 : yolov3模型
3 : yolov3_tiny模型
4 : yolov4模型
```

## 运行环境说明

NPU Demo 可以运行在X11或者framebuffer模式,Opencv3或者Opencv4的不同环境下.选择对应的demo运行即可.

### X11/Framebuffer

带有`fb`字样的demo是运行在framebuffer模式下.

带有`X11`字样的demo则是运行在桌面系统环境下.

### Opencv3/Opencv4


以`cv3`字样结尾的就是Opencv3环境下运行的demo

以`cv4`字样结尾的就是Opencv4环境下运行的demo

## 说明示例

这里以`detect_demo_picture`为例,

```shell
$ cd {workspace}/aml_npu_demo_binaries/detect_demo_picture
$ ls 
1080p.bmp  detect_demo_fb_cv3  detect_demo_fb_cv4  detect_demo_x11_cv3  detect_demo_x11_cv4  INSTALL  lib  nn_data  README.md  UNINSTALL
```

1. detect_demo_fb_cv3  是运行在framebuffer下使用opencv3的识别图片的demo
2. detect_demo_fb_cv4  是运行在framebuffer下使用opencv4的识别图片的demo
3. detect_demo_x11_cv3 是运行在X11下使用opencv3的识别图片的demo
4. detect_demo_x11_cv4 是运行在X11下使用opencv4的识别图片的demo


## 运行

### 图片识别

识别图片的命令格式

```shell
$ cd {workspace}/aml_npu_demo_binaries/detect_demo_picture
$ ./detect_demo_xx_xx type picture_path
```

这里以x11下使用Opencv3调用yolov3模型识别图片为例,

```shell
$ cd {workspace}/aml_npu_demo_binaries/detect_demo_picture
$ ./detect_demo_fb_cv3 2 1080p.bmp
```

运行结果如下,

![detect_demo_picture_x11_cv3](/images/vim3/detect_demo_picture_x11_cv3.png)

### 摄像头动态识别

摄像头说明

framebuffer下,使用USB摄像头应选用`uvc`的demo,使用mipi摄像头选用`mipi`的demo.

x11下,usb摄像头和mipi摄像头使用的是同一套demo.

摄像头动态识别的命令格式

```shell
$ cd {workspace}/aml_npu_demo_binaries/detect_demo
$ ./detect_xx_xx_xx <video node> <type>
```

这里以x11环境下使用opencv3调用yolov3为例,

```shell
$ cd {workspace}/aml_npu_demo_binaries/detect_demo
$ ./detect_demo_x11_cv3 /dev/video1 2
```

打开摄像头以后,会将识别的结果显示在屏幕上

![detect_demo_x11_cv3](/images/vim3/detect_demo_x11_cv3.png)













