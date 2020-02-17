<h1 id=file_notes>
    第04章 文件和目录
</h1>

[章节目录](../../README.md#title_ch04 "返回章节目录")
[函数表](func.md "进入函数表")
[类型表](type.md "进入类型表")

---

<h2 id=ch_4.2>
    函数stat、fstat、fstatat、lstat
</h2>

```c
int stat(const char *pathname, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *pathname, struct stat *buf);
int fstat(int fd, const char *name, struct stat *buf, int flag);

头文件：sys/stat.h
功能：获取文件的信息结构。
返回值：若成功返回0，出错返回-1。
形参说明：
示例代码：
```



---

[章节目录](../../README.md#title_ch04 "返回章节目录")
[函数表](func.md "进入函数表")
[类型表](type.md "进入类型表")
