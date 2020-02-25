# UNIX环境高级编程

记录阅读此书时发现的排版错误，或其他一些值得商榷的地方。



## 书籍版本

2014年6月第2版
2017年9月北京第15次印刷

## P75

在`struct stat`的介绍中，有三个成员拼写错误。


>```c
> struct timespec st_atime;
> struct timespec st_mtime;
> struct timespec st_ctime;
>```

应该修改为：
```c
 struct timespec st_atim;
 struct timespec st_mtim;
 struct timespec st_ctim;
```

在2008年以前的标准中，是如此定义的（注意类型）：
```c
time_t st_atime;
time_t st_mtime;
time_t st_ctime;
```

## P99

第4.19小节第二行，
> 每个文件`属性`所保存的实际精度依赖于文件系统的实现。

`属性`更换为`时间`可能更好一些。

TODO：待查阅英文原版。
