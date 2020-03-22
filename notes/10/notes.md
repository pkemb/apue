<h1 id=file_notes>
    第10章 信号
</h1>

[章节目录](../../README.md#title_ch10 "返回章节目录")
[函数表](func.md "进入函数表")

---

<h2 id=ch_10.2>
    信号概念
</h2>

* 信号是软中断，提供了一种处理异步事件的方法。
* 每个信号都有一个名字，以SIG开头。
* 信号被定义为一个`正整数`，即信号编号。可通过`kill -l`命令查看。
* 不存在编号为0的信号，POSIX.1将0称为空信号。

产生信号的条件：
* 当用户按某些终端键时，引发终端产生的信号。
> Delete, Ctrl+C, Ctrl+D
* 硬件异常产生信号，除数为0，无效的内存引用等。
* 进程调用kill函数将任意的信号值发送给另一个进程或进程组。
* 进程调用kill命令将信号发送给其他进程。
* 当检测到某种软条件发生时。

信号出现时的处理方式：
* 忽略此信号
> * SIGKILL 和 SIGSTOP不能被忽略。
> * 忽略硬件异常产生的信号，则进程的运行行为是未定义的。
* 捕捉信号，调用一个指定的用户函数。
* 执行系统默认动作。绝大多数信号的默认动作是终止进程。

常用信号及其产生条件：

<table>
    <tr><th>信号</th><th>产生条件</th></tr>
    <tr>
        <td>SIGABRT</td>
        <td>调用abort()函数产生此信号，进程异常终止。</td>
    </tr>
    <tr>
        <td>SIGALRM</td>
        <td>用alarm函数设置的定时器超时时，产生此信号。</td>
    </tr>
    <tr>
        <td>SIGBUS</td>
        <td>指示一个实现定义的硬件故障。</td>
    </tr>
    <tr>
        <td>SIGCHLD</td>
        <td>在一个进程终止或停止时，SIGCHLD信号被送给父进程。<br>
            注意，还有一个类似的信号SIGCLD（无H），具有不同的语义。</td>
    </tr>
    <tr>
        <td>SIGCONT</td>
        <td>此作业控制信号发送给需要继续运行，但当前处于停止状态的进程。</td>
    </tr>
    <tr>
        <td>SIGILL</td>
        <td>进程执行一条硬件非法指令。</td>
    </tr>
    <tr>
        <td>SIGINT</td>
        <td>用户按中断键时，终端驱动程序产生此信号并发送至前台进程组中的每一个进程。</td>
    </tr>
    <tr>
        <td>SIGKILL</td>
        <td>不能被捕捉或忽略，向系统管理员提供了一种可以杀死任一进程的可靠方法。</td>
    </tr>
    <tr>
        <td>SIGPIPE</td>
        <td>在管道的读进程已终止时写管道，则产生此信号。</td>
    </tr>
    <tr>
        <td>SIGQUIT</td>
        <td>当用户在终端上按退出键时，终端驱动程序产生此信号并发送给前台进程组中的所有进程。</td>
    </tr>
    <tr>
        <td>SIGSEGV</td>
        <td>进程进行了一次无效的内存引用。sementation violation。</td>
    </tr>
    <tr>
        <td>SIGSTOP</td>
        <td>不能被捕获或忽略。用于停止一个进程。</td>
    </tr>
    <tr>
        <td>SIGSYS</td>
        <td>无效的系统调用。</td>
    </tr>
    <tr>
        <td>SIGTSTP</td>
        <td>交互停止信号。用户在终端上按挂起键时，终端驱动程序产生此信号。</td>
    </tr>
    <tr>
        <td>SIGTTIN</td>
        <td>后台进程组尝试读终端时，终端驱动程序产生此信号。</td>
    </tr>
    <tr>
        <td>SIGTTOU</td>
        <td>后台进程组尝试写终端时，终端驱动程序产生此信号。</td>
    </tr>
</table>

<h2 id=ch_10.3>
    函数signal
</h2>

```c
#include <signal.h>
typedef void Sigfunc(int);
Sigfunc *signal(int signo, Sigfunc *func);
返回值：若成功，返回以前的信号处理方式；出错返回SIG_ERR。
功能：指定信号signo的处理方式func。
形参说明：
    signo：信号名。
    func：
        常量 SIG_IGN：忽略此信号。
        常量 SIG_DFL：系统默认动作。
        信号处理函数的地址：调用该函数
注意：
    signal的语义与实现有关，所以最好使用sigaction函数代替signal。
```

信号处理程序：返回值为void，带一个int类型的形参，其值为当前处理的信号。

signal需要改变信号的处理方式，才能确定型号的当前处理方式。而sigaction没有此限制。

exec调用：
* 将原先设置为要捕捉的信号都更改为默认动作。因为信号捕捉函数的地址在新程序中很可能无效。
fork调用：
* 子进程继承父进程的信号处理方式。因为信号捕捉函数的地址在子进程中是有意义的。

示例代码：<a href="code/test_signal.c">test_signal.c</a>

<h2 id=ch_10.4>
    不可靠信号
</h2>



---

[章节目录](../../README.md#title_ch10 "返回章节目录")
[函数表](func.md "进入函数表")