WindowsTerminal
=======

支持多选项卡、窗格、Unicode、UTF-8和自定义标题、主题、自动补全，支持WSL、PowerShell。

www.github.com/microsoft/terminal

https://docs.microsoft.com/zh-cn/windows/terminal/


默认快捷键
------

| 快捷键		| 功能		|
| ---- 			| ---- 		|
| Shift + Alt + +	|横向分屏	|
| Shift + Alt + -	|竖向分屏	|
| Ctrl + Shift + w	|取消分屏/关闭当前标签页|
| Alt + 方向键 		|分屏间移动光标	|
| Alt + Shift + 方向键	| 调整当前分屏区大小 |



settings.json
-----

	// 全局设置
	{
	    "$schema": "https://aka.ms/terminal-profiles-schema",

	    "defaultProfile": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}", // 默认配置文件

		"disabledProfileSources": "[]", // 禁用动态配置文件

		"theme": "system", // 深色/浅色主题

		"alwaysShowTabs": true, // 始终显示选项卡

		"tabWidthMode": "equal", // 选项卡宽度模式

		"confirmCloseAllTabs": true, // 隐藏关闭所有选项卡弹出窗口

		"startOnUserLogin": false, // 在计算机启动时启动

		"launchMode": "default", // 启动大小（窗口）

		"initialPosition": ",", // 启动位置（窗口）

		"initialCols": 120, // 首次启动时的列

		"initialRows": 30, // 首次启动时的行

		"showTabsInTitlebar": true, // 显示/隐藏标题栏

		"showTerminalTitleInTitlebar": true, // 设置标题栏中的文本

		"copyOnSelect": true, // 选择内容后复制

		"copyFormatting": true, // 复制格式

		//"wordDelimiters": "/\()"'-:,.;<>~!@#$%^&*|+=[]{}~?", // 字分隔符

		"rowsToScroll": "system", // 滚动速度

		"snapToGridOnResize": true, // 窗口大小调整行为

		"experimental.rendering.forceFullRepaint": true, // 屏幕重绘

		"experimental.rendering.software": true, // 软件渲染

		// 配置文件
	    "profiles":
	    {
			// 适用所有配置文件的设置
		"defaults":
		{
				"startingDirectory": "%USERPROFILE%", // 起始目录

				"icon": "D:\\QuectelLogo.png", // 图标

				"tabTitle": "BiaoNeverSurrender", // 自定义选项卡标题

				"suppressApplicationTitle": true, // 禁止shell更改标题

				"fontFace": "Fira Code Retina", // 字体

				"fontSize": 12, // 字体大小

				"fontWeight": "normal", // 字体粗细

				"padding": "8, 8, 8, 8", // 填充（内容距离界面的内部距离）

				"antialiasingMode": "cleartype", // 消除文本锯齿

				"cursorShape": "bar", // 光标形状

				"cursorColor": "#E6FF00", // 光标颜色

				//"cursorHeight": 25, // 光标高度（"cursorShape"设置为"vintage"时可用）

				"altGrAliasing": true, // AltGr别名

				"colorScheme": "Ubuntu", // 配色方案

				//"selectionBackground": "#0000e6", // 所选内容的背景色（选用"colorScheme"内的）

				"useAcrylic": true, // 启用 acrylic（毛玻璃特效）

				"acrylicOpacity": 0.9, // Acrylic 不透明度

				"backgroundImage": "C:\\Users\\DustinWinFiles\\Pictures\\colorful.jpg", // 背景图像设置

				"backgroundImageStretchMode": "uniformToFill", // 背景图像拉伸模式

				"backgroundImageAlignment": "center", // 背景图像对齐

				"backgroundImageOpacity": 0.5, // 背景图像不透明度

				"scrollbarState": "visible", // 滚动条可见性

				"snapOnInput": true, // 键入时滚动到输入行

				"historySize": 9001, // 历史记录大小

				"closeOnExit": "graceful", // 退出时配置文件的关闭方式（输入exit退出命令窗口）

				//"experimental.retroTerminalEffect": false // 怀旧式终端效果

				"alwaysOnTop": true // 始终处于顶部模式
		},

			// 配置文件列表
		"list":
		[
		    {
			"guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}", // PowerShell唯一标识符

			"name": "Windows PowerShell", // 名称

			"commandline": "powershell.exe", // 命令行

			"hidden": false // 隐藏下拉列表中的某个配置文件
		    },
		    {
			"guid": "{0caa0dad-35be-5f56-a8ff-afceeeaa6101}", // CMD唯一标识符

			"name": "命令提示符", // 名称

			"commandline": "cmd.exe", // 命令行

			"hidden": false // 隐藏下拉列表中的某个配置文件
		    },
		    {
			"guid": "{b453ae62-4e3d-5e58-b989-0a998ec441b8}", // Azure Cloud Shell唯一标识符

			"hidden": true, // 隐藏下拉列表中的某个配置文件

			"name": "Azure Cloud Shell", // 名称

			"source": "Windows.Terminal.Azure" // 源
		    },
		    {
			"guid": "{07b52e3e-de2c-5db4-bd2d-ba144ed6c273}",
			"hidden": false,
			"name": "Ubuntu-20.04",
			"source": "Windows.Terminal.Wsl"
		    },
		    {
			"guid": "{6f9994f0-4403-5e85-9cce-98e5da3839bb}",
			"hidden": false,
			"name": "Ubuntu-16.04",
			"source": "Windows.Terminal.Wsl"
		    }
		]
	    },

		// 主题（配色方案）
	    "schemes": [
			{
			  "name": "Ubuntu",

			  "black": "#2e3436",

			  "red": "#cc0000",

			  "green": "#4e9a06",

			  "yellow": "#c4a000",

			  "blue": "#3465a4",

			  "purple": "#75507b",

			  "cyan": "#06989a",

			  "white": "#d3d7cf",

			  "brightBlack": "#555753",

			  "brightRed": "#ef2929",

			  "brightGreen": "#8ae234",

			  "brightYellow": "#fce94f",

			  "brightBlue": "#729fcf",

			  "brightPurple": "#ad7fa8",

			  "brightCyan": "#34e2e2",

			  "brightWhite": "#eeeeec",

			  "background": "#300a24", // 背景色

			  "foreground": "#eeeeec" // 前景色
			}
		],

		// 按键绑定
	    "keybindings":
	    [
			{ "command": "closeWindow", "keys": "alt+f4" }, // 关闭窗口

			{ "command": "find", "keys": "ctrl+shift+f" }, // 查找

			{ "command": "openSettings", "keys": "ctrl+," }, // 打开设置文件

			{ "command": { "action": "openSettings", "target": "defaultsFile" }, "keys": "ctrl+alt+," }, // 打开设置文件

			{ "command": "toggleFullscreen", "keys": "alt+enter" }, // 切换全屏

			{ "command": "toggleFullscreen", "keys": "f11" }, // 切换全屏

			{ "command": "closeTab", "keys": "ctrl+alt+f4" }, // 关闭选项卡

			{ "command": "duplicateTab", "keys": "ctrl+shift+d" }, // 复制选项卡

			{ "command": "newTab", "keys": "ctrl+shift+t" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 0 }, "keys": "ctrl+shift+1" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 1 }, "keys": "ctrl+shift+2" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 2 }, "keys": "ctrl+shift+3" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 3 }, "keys": "ctrl+shift+4" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 4 }, "keys": "ctrl+shift+5" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 5 }, "keys": "ctrl+shift+6" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 6 }, "keys": "ctrl+shift+7" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 7 }, "keys": "ctrl+shift+8" }, // 新建选项卡

			{ "command": { "action": "newTab", "index": 8 }, "keys": "ctrl+shift+9" }, // 新建选项卡

			{ "command": "nextTab", "keys": "ctrl+tab" }, // 打开下一个选项卡

			{ "command": "prevTab", "keys": "ctrl+shift+tab" }, // 打开上一个选项卡

			{ "command": { "action": "switchToTab", "index": 0 }, "keys": "ctrl+alt+1" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 1 }, "keys": "ctrl+alt+2" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 2 }, "keys": "ctrl+alt+3" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 3 }, "keys": "ctrl+alt+4" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 4 }, "keys": "ctrl+alt+5" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 5 }, "keys": "ctrl+alt+6" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 6 }, "keys": "ctrl+alt+7" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 7 }, "keys": "ctrl+alt+8" }, // 打开特定的选项卡

			{ "command": { "action": "switchToTab", "index": 8 }, "keys": "ctrl+alt+9" }, // 打开特定的选项卡

			{ "command": "closePane", "keys": "ctrl+shift+w" }, // 关闭窗格

			{ "command": { "action": "moveFocus", "direction": "down" }, "keys": "alt+down" }, // 移动窗格焦点

			{ "command": { "action": "moveFocus", "direction": "left" }, "keys": "alt+left" }, // 移动窗格焦点

			{ "command": { "action": "moveFocus", "direction": "right" }, "keys": "alt+right" }, // 移动窗格焦点

			{ "command": { "action": "moveFocus", "direction": "up" }, "keys": "alt+up" }, // 移动窗格焦点

			{ "command": { "action": "resizePane", "direction": "down" }, "keys": "alt+shift+down" }, // 调整窗格大小

			{ "command": { "action": "resizePane", "direction": "left" }, "keys": "alt+shift+left" }, // 调整窗格大小

			{ "command": { "action": "resizePane", "direction": "right" }, "keys": "alt+shift+right" }, // 调整窗格大小

			{ "command": { "action": "resizePane", "direction": "up" }, "keys": "alt+shift+up" }, // 调整窗格大小

			{ "command": { "action": "splitPane", "split": "auto", "splitMode": "duplicate" }, "keys": "alt+shift+d" }, // 拆分窗格

			{ "command": { "action": "splitPane", "split": "horizontal"}, "keys": "alt+shift+-" }, // 拆分窗格

			{ "command": { "action": "splitPane", "split": "vertical"}, "keys": "alt+shift+plus" }, // 拆分窗格

			{ "command": { "action": "copy", "singleLine": false }, "keys": "ctrl+c" }, // 复制

			{ "command": { "action": "copy", "singleLine": false }, "keys": "ctrl+shift+c" }, // 复制

			{ "command": { "action": "copy", "singleLine": false }, "keys": "ctrl+insert" }, // 复制

			{ "command": "paste", "keys": "ctrl+v" }, // 粘贴

			{ "command": "paste", "keys": "ctrl+shift+v" }, // 粘贴

			{ "command": "paste", "keys": "shift+insert" }, // 粘贴

			{ "command": "scrollUp", "keys": "ctrl+shift+up" }, // 向上滚动

			{ "command": "scrollDown", "keys": "ctrl+shift+down" }, // 向下滚动

			{ "command": "scrollUpPage", "keys": "ctrl+shift+pgup" }, // 向上滚动一整页

			{ "command": "scrollDownPage", "keys": "ctrl+shift+pgdn" }, // 向下滚动一整页

			{ "command": { "action": "adjustFontSize", "delta": 1 }, "keys": "ctrl+=" }, // 调整字号

			{ "command": { "action": "adjustFontSize", "delta": -1 }, "keys": "ctrl+-" }, // 调整字号

			{ "command": "resetFontSize", "keys": "ctrl+0" }, // 重置字号

			//{ "command": "unbound", "keys": "ctrl+q" } // 取消绑定键

			{ "command": "toggleFocusMode", "keys": "shift+f11" }, // 对焦模式

			{ "command": "toggleAlwaysOnTop", "keys": "alt+shift+tab" }, // 始终处于顶部模式

			{ "command": { "action": "setTabColor", "color": "#ffffff" }, "keys": "ctrl+a" }, // 设置选项卡颜色

			{ "command": "openTabColorPicker", "keys": "ctrl+b" }, // 打开选项卡颜色选取器

			{ "command": "renameTab", "keys": "ctrl+c" }, // 重命名选项卡

			{ "command": "toggleRetroEffect", "keys": "ctrl+d" }, // 切换复古终端效果

			{ "command": "commandPalette", "keys": "ctrl+shift+p" } // 命令调色板
	    ]
	}


