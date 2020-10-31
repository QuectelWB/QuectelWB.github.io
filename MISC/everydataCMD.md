learn a cmd each day
======

每天熟悉一个命令


pstree
----

![](pstree.png)

```help
pstree: unrecognized option '--help'
用法：pstree [-acglpsStTuZ] [ -h | -H 进程号 ] [ -n | -N 类型 ]
              [ -A | -G | -U ] [ 进程号 | 用户 ]
  或：pstree -V

显示进程树。

  -a, --arguments     显示命令行参数
  -A, --ascii         使用 ASCII 行绘制字符
  -c, --compact-not   不要对完全相同的子树进行压缩
  -C, --color=类型    按照指定属性对进程上色
                      (age)
  -g, --show-pgids    显示进程组 ID；隐含启用 -c 选项
  -G, --vt100         使用 VT100 行绘制字符
  -h, --highlight-all 高亮显示当前进程和其所有祖先
  -H PID, --highlight-pid=PID
                      高亮显示指定 PID 对应的进程和其所有祖先
  -l, --long          不要截断长行
  -n, --numeric-sort  按照 PID 对输出进行排序
  -N 类型, --ns-sort=类型
                      按照指定命名空间类型对输出进行排序
                              (cgroup, ipc, mnt, net, pid, user, uts)
  -p, --show-pids     显示 PID；隐含启用 -c 选项
  -s, --show-parents  显示所选进程的父进程
  -S, --ns-changes    显示命名空间的变化
  -t, --thread-names  显示完整线程名称
  -T, --hide-threads  隐藏线程，只显示进程
  -u, --uid-changes   显示用户 ID（UID）的变化
  -U, --unicode       使用 UTF-8（Unicode）的行绘制字符
  -V, --version       显示版本信息
  -Z, --security-context
                      显示 SELinux 安全上下文

  进程号 从指定进程号开始；默认为 1（init）
  用户   仅显示从指定用户的进程开始的进程树
```


pidof
-------

root@m:/usr/src/linux-headers-5.4.0-26-generic/include# ps -a
    PID TTY          TIME CMD
   2097 pts/0    00:00:00 sudo
   2948 pts/1    00:00:00 bash
   2969 pts/0    00:00:00 tmux: client
  45805 pts/9    00:00:00 ps
root@m:/usr/src/linux-headers-5.4.0-26-generic/include# pidof tmux
2971 2969


chroot
------
命令用于改变根目录




-----





