<h1 id=file_notes>
    第12章 线程控制
</h1>

[章节目录](../../README.md#title_ch12 "返回章节目录")
[函数表](func.md "进入函数表")

---

<h2 id=ch_12.2>
    线程限制
</h2>

为了增强应用程序在不同的操作系统实现之间的可移植性，SUS定义了一些与线程操作有关的限制：

<table>
    <tr><th>限制名称</th><th>描述</th><th>name参数</th></tr>
    <tr>
        <td>PTHREAD_DESTRUCTOR_ITERATIONS</td>
        <td>线程退出时操作系统实现试图销毁线程特定数据的最大次数。</td>
        <td>_SC_THREAD_DESTRUCTOR_ITERATIONS</td>
    </tr>
    <tr>
        <td>PTHREAD_KEYS_MAX</td>
        <td>进程可以创建的键的最大数目。</td>
        <td>_SC_THREAD_KEYS_MAX</td>
    </tr>
    <tr>
        <td>PTHREAD_STACK_MIN</td>
        <td>一个线程的栈可用的最小字节数</td>
        <td>_SC_THREAD_STACK_MIN</td>
    </tr>
    <tr>
        <td>PTHREAD_THREADS_MAX</td>
        <td>进程可以创建的最大线程数</td>
        <td>_SC_THREAD_THREADS_MAX</td>
    </tr>
</table>

---

[章节目录](../../README.md#title_ch12 "返回章节目录")
[函数表](func.md "进入函数表")