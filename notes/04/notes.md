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
int fstatat(int fd, const char *pathname, struct stat *buf, int flag);

头文件：sys/stat.h
功能：获取文件的信息结构。
返回值：若成功返回0，出错返回-1。
说明：
    stat()获取文件pathname的信息结构；
    如果文件是符号链接，lstat()将返回符号链接本身的信息，而不是指向的文件。
    fstat()返回在描述符fd上打开的文件的信息结构。

    fstatat() 返回相对于当前打开目录(fd)的路径名的信息结构。
    flag参数：AT_SYMLINK_NOFOLLOW被置位，返回符号链接本身的信息，而不是指向的文件。
    (1)pathname是绝对路径，忽略fd参数。
    (2)pathname是相对路径，开始地址是 fd 指向的目录。
    (3)pathname是相对路径，fd 参数等于 AT_FDCWD，开始地址是 当前工作目录。
示例代码：
```

<h2 id=ch_4.3>
    文件类型
</h2>

下表列出了UNIX系统的文件类型。文件类型存储在`stat`结构体中的`st_mode`成员中，可用下表中的宏`S_ISxxx()`来测试文件类型。将`st_mode`与宏`S_IFMT`位与，然后和宏`S_IFxxx`比较，也可以得到文件类型。即：

```c
#define S_ISDIR(mode)    (((mode) & S_IFMT) == S_IFDIR)
```

<table>
    <tr><th>文件类型</th><th>说明</th><th>宏</th></tr>
    <tr>
        <td>普通文件 regular file</td>
        <td>最常用的文件类型，包含了某种形式的数据。</td>
        <td>S_ISREG() S_IFREG</td>
    </tr>
    <tr>
        <td>目录文件 directory file</td>
        <td>包含了其他文件的名字以及指向这些文件有关信息的指针。</td>
        <td>S_ISDIR() S_IFDIR</td>
    </tr>
    <tr>
        <td>块特殊文件 block special file</td>
        <td>提供对设备带缓冲的访问，每次访问以固定长度进行。</td>
        <td>S_ISBLK() S_IFBLK</td>
    </tr>
    <tr>
        <td>字符特殊文件 character special file</td>
        <td>提供对设备不带缓冲的访问，每次访问长度可变。</td>
        <td>S_ISCHR() S_IFCHR</td>
    </tr>
    <tr>
        <td>FIFO</td>
        <td>用于进程间通信，有时也称为命名管道。</td>
        <td>S_ISFIFO() S_IFFIFO</td>
    </tr>
    <tr>
        <td>套接字 socket</td>
        <td>用于进程间的网络通信。</td>
        <td>S_ISSOCK() S_IFSOCK</td>
    </tr>
    <tr>
        <td>符号链接 symbolic link</td>
        <td>指向另一个文件。</td>
        <td>S_ISLNK() S_IFLNK</td>
    </tr>
</table>

<h2 id=ch_4.4>
    设置用户ID (SUID) 和设置组ID (SGID)
</h2>

与<font color="red"><b>进程</b></font>相关的ID。通常，<font color="red">有效用户ID</font>等于<font color="red">实际用户ID</font>；<font color="blue">有效组ID</font>等于<font color="blue">实际组ID</font>。

<b></b>

<table>
    <tr><th>ID</th><th>说明</th>
    <tr>
        <td><font color="red">实际用户ID</font></td>
        <td rowspan="2">实际上是谁，在登录时取自口令文件中的登录项</td>
    </tr>
    <tr><td><font color="blue">实际组ID</font></td></tr>
    <tr>
        <td><font color="red">有效用户ID</font></td>
        <td rowspan="3">用于文件访问检查</td>
    </tr>
    <tr><td><font color="blue">有效组ID</font></td></tr>
    <tr>
        <td>附属组ID</td>
    </tr>
    <tr>
        <td><font color="red">保存的设置用户ID</font></td>
        <td>有效用户ID的副本</td>
    </tr>
    <tr>
        <td><font color="blue">保存的设置组ID</font></td>
        <td>有效组ID的副本</td>
    </tr>
</table>

与<font color="red"><b>文件</b></font>相关的ID

文件所有者：`stat` 结构中的 `st_uid` \
文件所属组：`stat` 结构中的 `st_gid`

当执行一个文件时，(进程的)有效用户ID等于(登录用户的)实际用户ID。也就是说，与文件没有关系。如果文件的`设置用户ID（SUID）`置位，那么，(进程的)有效用户ID等于文件的所有者。

有效组ID也是类似的。

SUID 和 SGID 存储在 stat 结构体中的 st_mode 成员中。可用宏 S_ISUID() S_ISGID() 测试。

---

[章节目录](../../README.md#title_ch04 "返回章节目录")
[函数表](func.md "进入函数表")
[类型表](type.md "进入类型表")
