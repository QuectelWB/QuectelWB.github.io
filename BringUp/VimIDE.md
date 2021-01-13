vim
=====


ctags
----

ctags的功能：扫描指定的源文件，找出其中所包含的语法元素，并将找到的相关内容记录下来。

####1 查看ctags支持的语言
ctags --list-languages

####2 查看语言和扩展名的对应关系
ctags --list-maps

####3 查看ctags可以识别和记录的语法元素
ctags --list-kinds

单独查看可以识别的C++的语法元素：

[chuxing@hostname ~]$ ctags --list-kinds=c++
c  classes
d  macro definitions
e  enumerators (values inside an enumeration)
f  function definitions
g  enumeration names
l  local variables [off]
m  class, struct, and union members
n  namespaces
p  function prototypes [off]
s  structure names
t  typedefs
u  union names
v  variable definitions
x  external and forward variable declarations [off]


##### 对当前目录下所有ctags支持的语言格式文件生成tags
ctags -R *

缺点很明显，tags会非常大，tags生成会非常慢，而且代码跳转会卡顿。

#### 只对特定文件生成tags
ctags `find -name "*.h"`

#### 使用tags
> tag命令
用于跳转到指定的tag。例如：

	tag tagname

使用这个命令可以跳转到tagname的定义处，即使它在另一个文件中。

> 快捷键Ctrl+]
取出当前光标下的word作为tag的名字并进行跳转。

>  tags命令
列出曾经访问过的tag的列表

>  快捷键Ctrl+T
跳转到前一次的tag处。

> stag命令
stag tagname

分割当前窗口，并且跳转到指定的tag。

> 快捷键Ctrl+W+]
分割当前窗口，并且跳转到光标下的tag。

> 同名tag
如果存在多个同名的tag，tag命令会给出一个tag的列表，可以通过键入tag的序号来选择tag；也可以通过tselect来过滤tag，如：:tselect tagname

如果要在多个tag间移动，可以使用如下命令：

	:tfirst             go to first match
	:[count]tprevious   go to [count] previous match
	:[count]tnext       go to [count] next match
	:tlast              go to last match


如果没有指定[count]，默认是1。

#### 其他

如果是多个tags文件，可以通过设置tags选项来引入更多的tags文件。例如: :set tags=./tags, ./../tags, ./*/tags
使用tag命令时，可以输入部分tag名，然后使用Tab键进行补全。


vim
--------

#### 打开文件时启动分屏

使用Vim打开文件时，可以通过参数-On 或 -on来启动分屏。

n 代表整数，表示将整个屏幕分成n部分

大写 O 表示进行垂直方向分屏，小写 o 表示水平方向进行分屏

#### Vim内部启动分屏

使用Vim打开文件后，仍然可以在尾行模式通过以下命令进行屏幕分割

**垂直分屏并打开一个新文件**

	:vsplit filename 或缩写形式 :vsp filename

v 表示单词 vertical，是中文垂直的意思

**水平分屏并打开一个新文件**


	Vim尾行模式下执行命令 :split filename 或缩写形式 :sp filename 


**垂直分隔当前打开的文件**

	Vim命令行模式下执行命令 Ctrl+w v 可将当前打开的文件进行垂直分割

上述命令 Ctrl+w v 的意思是：先同时按键 Ctrl 和 w，再按键 v


**水平分隔当前打开的文件**

	ctrl+w s 可将当前打开的文件进行水平方向分割

上述命令 Ctrl+w s 表示先同时按键 Ctrl 和 w，再按键 s


#### 分屏大小

	命令 Ctrl+w = 表示设置所有的分屏幕都有相同的高度

	命令 Ctrl+w + 用于增加当前屏幕的高度

	命令 Ctrl+w - 用于减少当前屏幕的高度

#### 关闭Vim分屏

ctrl +w c

Tips
----

vim 中执行命令

	:!ls

