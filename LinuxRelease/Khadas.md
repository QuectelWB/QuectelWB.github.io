Khadas
=====

Web
----

[DOCs](https://docs.khadas.com/)

[KVim3](https://docs.khadas.com/zh-cn/vim3/index.html)

[Github](https://github.com/khadas)

[Forum](https://forum.khadas.com/)


Android
----

> repo 工具
	
	export REPO_URL='https://mirrors.tuna.tsinghua.edu.cn/git/git-repo'
	
> 官方推荐的是按照[Android](https://docs.khadas.com/vim3/DownloadAndroidSourceCode.html)

	repo init -u https://github.com/khadas/android_manifest.git -b khadas-vims-pie

实际上不可行。因为国内访问不了谷歌。AOSP无法下载。

办法是修改.repo/manifests/default.xml,按照清华大学镜像网站的方法

[清华大学 Android 镜像使用帮助](https://mirrors.tuna.tsinghua.edu.cn/help/AOSP/)

将 https://android.googlesource.com/ 全部使用 https://mirrors.tuna.tsinghua.edu.cn/git/AOSP/ 代替即可。

但是，由于直接修改xml会导致第一次repo sync失败后第二次失败。将https://github.com/khadas/android_manifest.git fork一份到自己的github空间，并修改khadas-vims-pi分支对应的default.script

后续尝试，可以直接使用自己的git仓库里的

	repo init -u https://github.com/MrVW/android_manifest.git -b khadas-vims-pie

> 防止sync 失败，失败后不断重试


	#!/bin/bash   
	
	
	repo sync   -j1 --fail-fast
	while [ $? = 1 ]; do   
			echo "================sync failed, re-sync again ====="   
		sleep 3   
		repo sync   -j1 --fail-fast
	done



$?：获取函数返回值或者上一个命令的退出状态




:)
