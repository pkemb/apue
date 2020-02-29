<h1 id=file_func>
    第07章 进程环境
</h1>

[章节目录](../../README.md#title_ch07 "返回章节目录")
[笔记](notes.md "进入笔记")

----

<table>
    <tr>
        <th>序号</th><th>函数原型</th><th>头文件</th><th>说明</th>
    </tr>
    <tr>
        <td>1</td>
        <td>void exit(int status);</td>
        <td>stdlib.h</td>
        <td>ISO C</td>
    </tr>
    <tr>
        <td>2</td>
        <td>void _Exit(int status);</td>
        <td>stdlib.h</td>
        <td>POSIX.1</td>
    </tr>
    <tr>
        <td>3</td>
        <td>void _exit(int status);</td>
        <td>unistd.h</td>
        <td>POSIX.1</td>
    </tr>
    <tr>
        <td>4</td>
        <td>int atexit(void (*func)(void));</td>
        <td>stdlib.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>序号</td>
        <td>函数原型</td>
        <td>头文件</td>
        <td>说明</td>
    </tr>
</table>