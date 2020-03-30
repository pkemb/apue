<h1 id=file_func>
    第10章 信号
</h1>

[章节目录](../../README.md#title_ch10 "返回章节目录")
[笔记](notes.md "进入笔记")

---

<table>
    <tr>
        <th>序号</th><th>函数原型</th><th>头文件</th><th>说明</th>
    </tr>
    <tr>
        <td>1</td>
        <td>void (*signal(int signo, void (*func)(int)))(int);</td>
        <td>signal.h</td>
        <td>设置信号处理程序。</td>
    </tr>
    <tr>
        <td>2</td>
        <td>int kill(pid_t pid, int signo);</td>
        <td>signal.g</td>
        <td>向进程或进程组发送信号。</td>
    </tr>
    <tr>
        <td>3</td>
        <td>int raise(int signo);</td>
        <td>signal.h</td>
        <td>向调用进程发送信号。</td>
    </tr>
    <tr>
        <td>序号</td>
        <td>函数原型</td>
        <td>头文件</td>
        <td>说明</td>
    </tr>
</table>
