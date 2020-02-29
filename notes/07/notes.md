<h1 id=file_notes>
    第07章 进程环境
</h1>

[章节目录](../../README.md#title_ch07 "返回章节目录")
[函数表](func.md "进入函数表")

---

<h2 id=ch_7.1>
    main函数
</h2>

* 函数原型：`int main(int argc, char *argv[])`。
* argc 是命令行参数的个数，argv是指向参数的各个指针所构成的数组。
* mian函数在调用之前，内核会调用一个特殊的启动例程。
* 启动例程从内核取得命令行参数和环境变量值。

<h2 id=ch_7.3>
    进程终止
</h2>

进程终止的8种方法：
1) 从 mian 返回；
2) 调用 exit；
3) 调用 _exit 或 _Exit；
4) 最后一个线程从其启动例程返回；
5) 从最后一个线程调用 pthread_exit；
6) 调用 abort；
7) 接到一个信号；
8) 最后一个线程对取消请求做出响应。

<h3 id=func_exit>
    退出函数
</h3>

<table>
    <tr>
        <th>所属标准</th><th>函数原型</th>
        <th>头文件</th><th>说明</th>
    </tr>
    <tr>
        <td rowspan="2">ISO C</td>
        <td>void exit(int status);</td>
        <td rowspan="2">stdlib.h</td>
        <td>先执行一些清理动作，再调用 _Exit() 或 _exit</td>
    </tr>
    <tr>
        <td>void _Exit(int status)</td>
        <td rowspan="2">立即进入内核</td>
    </tr>
    <tr>
        <td>POSIX.1</td>
        <td>void _exit(int status)</td>
        <td>unistd.h</td>
    </tr>
</table>

形参`status`被称为`终止状态`。main()函数返回一个整型值与用该值调用 exit 是等价的。

<h3 id=func_atexit>
    函数atexit
</h3>

```c
int atexit(void (*func)(void));

头文件：stdlib.h
返回值：成功返回0，出错返回非0。
功能：登记终止处理程序。
```

关于`终止处理程序`的一些说明：
* 终止处理程序由 exit() 自动调用；
* 一个进程最多支持32个终止处理程序（可能有扩展）；
* exit 调用的顺序与登记的顺序相反。
* 同一个函数被登记多次，也会执行多次。

<h2 id=pic_c_progrm_start_and_exit>
    一个C程序是如何启动和终止的
</h2>

* 内核使程序执行的唯一方法是调用一个 exec 函数。
* 进程自愿终止的唯一方法是显式或隐式地调用_exit或_Exit。

<div style="text-align:center">
	<img src="pic/c_program_start_and_exit.png" align=center />
</div>

<h2 id=ch_7.4>
    命令行参数
</h2>

当执行一个程序时，调用exec的进程可将命令行参数传递给该新程序
* argv[0] 通常是程序名
* ISO C和POSIX.1都要求 argv[argc]是一个空指针
* 如果创建一个符号链接指向某一个程序。当执行符号链接时，argv[0]将会是符号链接的名字。busybox等工具的实现方式。

<h2 id=ch_7.5>
    环境表
</h2>

* 全局变量`environ`包含了环境表的地址。
```c
extern char **environ;
```
* 需要显示的使用 extern 声明此变量
* 按照惯例，环境变量由`name=value`这样的字符串组成。
* 通常使用 `getenv()` 和 `setenv()` 来访问特定的环境变量。
* 如果要查看所有的环境变量，则必须使用 environ 变量。

示例代码：<a href="code/test_environ.c">test_environ.c</a>

---

[章节目录](../../README.md#title_ch07 "返回章节目录")
[函数表](func.md "进入函数表")