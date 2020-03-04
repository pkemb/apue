<h1 id=file_notes>
    第08章 进程控制
</h1>

[章节目录](../../README.md#title_ch08 "返回章节目录")
[函数表](func.md "进入函数表")

---

<h2 id=ch_8.2>
    进程标识
</h2>

<table>
    <tr>
        <th>标识</th><th>获取函数</th><th>说明</th>
    </tr>
    <tr>
        <td>进程ID</td>
        <td>pid_t getpid(void);</td>
        <td>非负，唯一，可复用。<br>
            ID为0的进程通常是调度进程，运行在内核，是内核的一部分。<br>
            ID为1的进程通常是init进程，负责在自举内核后启动一个UNIX系统。<br>
            init进程决不会终止，是一个普通的用户进程。</td>
    </tr>
    <tr>
        <td>父进程ID</td>
        <td>pid_t getppid(void);</td>
        <td>调用进程的父进程ID。</td>
    </tr>
    <tr>
        <td>实际用户ID</td>
        <td>uid_t getuid(void);</td>
        <td>调用进程的实际用户ID</td>
    </tr>
    <tr>
        <td>有效用户ID</td>
        <td>uid_t geteuid(void);</td>
        <td>调用进程的有效用户ID。</td>
    </tr>
    <tr>
        <td>实际组ID</td>
        <td>gid_t getgid(void);</td>
        <td>调用进程的实际组ID。</td>
    </tr>
    <tr>
        <td>有效组ID</td>
        <td>gid_t getegid(void);</td>
        <td>调用进程的有效组ID。</td>
    </tr>
</table>

注：
* 使用以上函数需要包含头文件 unistd.h
* 都没有出错返回。

示例代码：<a href="code/test_getpid.c">test_getpid.c</a>

<h2 id=ch_8.3>
    函数 fork
</h2>

```c
pid_t fork(void);

头文件：unistd.h
功能：创建一个新进程。
返回值：父进程返回子进程的ID，子进程返回0。若出错返回-1。
```

* 子进程和父进程继续制定fork()之后的指令。
* 子进程是父进程的副本。
> 子进程和父进程共享正文段；子进程获得父进程数据空间、堆和栈的副本（不是共享），采用写时复制（CoW）的技术。
* 子进程和父进程的执行先后顺序是不确定的。如需同步，需要某种形式的进程间通信。
* 父进程所有打开的文件描述符都被复制到子进程中，并且共享同一个文件表项。所以文件偏移量也是共享的。

*注意理解书中的例程，fork与 I/O 函数之间的交互关系。*
* 在fork之前，输出一串字符（含换行符）到缓冲区。
* 如果是行缓冲，会立即flush，不会复制到子进程。
* 如果是全缓冲，会复制一份到子进程。那么，父进程和子进程都会输出一份。

fort的两种常见用法：
1) 一个父进程希望复制自己，使父进程和子进程同时执行不同的代码段。如网络服务进程。
2) 一个进程要执行一个不同的程序，子进程在 fork 返回后立即执行 exec。如shell。

子进程继承了父进程的绝大部分属性，但有以下不同：
* 子进程的 tms_utims tms_stime tms_cutime tms_ustime设置为0。
* 子进程不继承父进程设置的文件锁。
* 子进程的未处理闹钟被清楚。
* 子进程的未处理信号集设置为空集。

示例代码：<a href="code/test_fork.c">test_fork.c</a>

---

[章节目录](../../README.md#title_ch08 "返回章节目录")
[函数表](func.md "进入函数表")
