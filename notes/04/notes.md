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

<h2 id=ch_4.5>
    文件访问权限
</h2>

`st_mode`包含了对文件的访问权限位，可用以下宏来测试。
<table>
    <tr>
        <th>st_mode屏蔽位</th><th>含义</th>
        <th>st_mode屏蔽位</th><th>含义</th>
        <th>st_mode屏蔽位</th><th>含义</th>
    </tr>
    <tr>
        <td>S_IRUSR</td><td>用户读</td>
        <td>S_IWUSR</td><td>用户写</td>
        <td>S_IXUSR</td><td>用户执行</td>
    </tr>
    <tr>
        <td>S_IRGRP</td><td>组读</td>
        <td>S_IWGRP</td><td>组写</td>
        <td>S_IXGRP</td><td>组执行</td>
    </tr>
    <tr>
        <td>S_IROTH</td><td>其他读</td>
        <td>S_IWOTH</td><td>其他写</td>
        <td>S_IXOTH</td><td>其他执行</td>
    </tr>
</table>

文件访问权限的规则：
1) 打开任一类型的文件，对该名字中包含的每一个目录，以及当前工作目录，都要有执行权限。
> 目录的读权限：获取该目录中所有文件名的列表 \
> 目录的执行权限：可通过该目录访问一个文件 \
> 如果PATH变量指定了一个不具有执行权限的目录，shell不会在此目录下寻找可执行文件
2) 文件的读权限：打开文件进行读操作。
> 与open 函数的 O_RDONLY 和 O_RDWR 标志有关。
3) 文件的写权限：打开文件进行写操作。
> 与open函数的 O_WRONLY 和 O_RDWR标志有关。
4) open 函数指定 O_TRUNC 标志时，必须具有写权限。
5) 在目录中创建一个文件，对所在目录必须有写权限和执行权限
6) 删除一个文件，对所在目录必须有写权限和执行权限，对文件本身不需要读写权限。
7) exec执行某个文件，必须有执行权限，且是一个普通文件。

文件权限的测试： \
进程打开、创建、删除一个文件时，内核会进行权限的测试。
测试过程涉及到文件的所有者(`st_uid`)、文件的所属组(`st_gid`)，
以及进程的`有效用户ID`和`有效组ID`。
1) 如果进程的`有效用户ID`是root，允许访问（忽略了文件的权限位）
2) 如果进程的`有效用户ID`和文件的`st_uid`相同，如果所有者适当的访问权限位打开，则允许访问。否则拒绝访问。
3) 如果进程的`有效组ID`和文件的`st_gid`相同，如果所属组适当的访问权限位打开，允许访问，否则拒绝。
4) 若其他用户的适当权限位被设置，允许访问，否则拒绝。
> 注：如果（2）测试失败，则（3）和（4）不会测试；其他类似。 \
> 适当的访问权限是指：若进程为读而打开该文件，则用户读位应为1。其他类似。

<h2 id=ch_4.6>
    新文件和目录的所有权
</h2>

新文件（目录）的所有者是进程的有效用户ID。 \
新文件（目录）的组ID可以是下列之一： \
1) 进程的有效组ID
2) 所在目录的组ID（可以做到向下传递权限）
> 对于Linux来说，如果目录的设置组ID位（`SGID`）被设置，则是(2)；否则(1)。

<h2 id=ch_4.7>
函数 access 和 faccessat
</h2>

```c
int access(const char *pathname, int mode);
int faccessat(int fd, const char *pathname, int mode, int flag);

头文件：unistd.h
功能：以进程的实际用户ID和实际组ID来测试访问权限。
      open()函数使用有效用户ID和有效组ID来测试。
返回值：成功(有权限)返回0，出错(没有权限)返回-1。
形参说明：
    pathname：测试文件的文件名
    mode：测试的权限，详细见下表。
    flag：更改 faccessat()的行为，如果取值为 AT_EACCESS，
          访问检查用进程的有效用户ID和有效组ID。
    fd：
        (1)pathname 为绝对路径，忽略此参数。
        (2)pathname 为相对路径，fd 指出起始目录。
        (3)pathname 为相对路径，fd 取值为 AT_FDCWD，起始目录为当前工作目录。
```

形参`mode`指明需要测试的权限，按以下常量位或：

<table>
    <tr><th>mode</th><th>说明</th><th>头文件</th></tr>
    <tr><td>R_OK</td><td>测试读权限</td><td rowspan="4">unistd.h</td></tr>
    <tr><td>W_OK</td><td>测试写权限</td></tr>
    <tr><td>X_OK</td><td>测试执行权限</td></tr>
    <tr><td>F_OK</td><td>测试文件是否存在</td></tr>
</table>

<h2 id=ch_4.8>
    函数 umask
</h2>

```c
mode_t umask(mode_t cmask);

头文件：sys/stat.h
功能：为进程设置文件模式创建屏蔽字，并返回之前的值。
返回值：之前的文件模式创建屏蔽字。
说明：
    cmask：由 S_IRUSER S_IWUSR 等常量按位或构成。
           umask 中为1的位，新建文件对应的权限一定被关闭。
```

> 在shell中，可用umask命令查看或设置文件模式创建屏蔽字。

<h2 id=ch_4.9>
    函数 chmod、fchmod、fchmodat
</h2>

```c
int chmod(const char *pathname, mode_t mode);
int fchmod(int fd, mode_t mode);
int fchmodat(int fd, const char *pathname, mode_t mode, int flag);

头文件：sys/stat.h
功能：更改现有文件的访问权限。
返回值：成功返回0，出错返回-1。
形参说明：
    pathname：文件名。
    mode：新的访问权限。下图所示常量的按位或。
    flag：取值为 AT_SYMLINK_NOFOLLOW时，不会跟随符号链接。

区别：
fchmod() 对已打开的文件进行操作。
fchmodat()：
           (1) pathname 为绝对路径，忽略fd参数。
           (2) pathname 为相对路径，fd 指出起始目录。
           (3) pathname 为相对路径，fd 取值为 AT_FDCWD，起始目录为当前工作目录。
```
> 为了改变一个文件的权限位，进程的`有效用户ID`必须等于`文件的所有者ID`或`root`。

<table>
    <tr><th>mode</th><th>说明</th></tr>
    <tr><td>S_ISUID</td><td>执行时设置用户ID</td></tr>
    <tr><td>S_ISGID</td><td></td>执行时设置组ID</tr>
    <tr><td>S_ISVTX</td><td></td>保存正文（粘着位）</tr>
    <tr><td></td><td></td></tr>
    <tr><td>S_IRWXU</td><td>用户读、写和执行</td></tr>
    <tr><td>S_IRUSR</td><td></td>用户读</tr>
    <tr><td>S_IWUSR</td><td></td>用户写</tr>
    <tr><td>S_IXUSR</td><td></td>用户执行</tr>
    <tr><td></td><td></td></tr>
    <tr><td>S_IRWXG</td><td>组读、写和执行</td></tr>
    <tr><td>S_IRGRP</td><td>组读</td></tr>
    <tr><td>S_IWGRP</td><td>组写</td></tr>
    <tr><td>S_IXGRP</td><td>组执行</td></tr>
    <tr><td></td><td></td></tr>
    <tr><td>S_IRWXO</td><td>其他读、写和执行</td></tr>
    <tr><td>S_IROTH</td><td>其他读</td></tr>
    <tr><td>S_IWOTH</td><td>其他写</td></tr>
    <tr><td>S_IXOTH</td><td>其他执行</td></tr>
</table>

`chmod()`将在下列条件自动清除两个权限位：
1) Solaris等系统，试图设置普通文件的S_ISVTX权限位，而没有root权限，那么S_ISVTX将会自动关闭。
2) 如果新文件的组ID不等于进程的有效组ID或者进程的附属组ID中的一个，而且进程没有root权限，那么S_ISGID会被自动关闭。
> 新创建文件的组ID可能是父目录的组ID。

---

[章节目录](../../README.md#title_ch04 "返回章节目录")
[函数表](func.md "进入函数表")
[类型表](type.md "进入类型表")
