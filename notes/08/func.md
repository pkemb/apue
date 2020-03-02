<h1 id=file_func>
    第08章 进程控制
</h1>

[章节目录](../../README.md#title_ch08 "返回章节目录")
[笔记](notes.md "进入笔记")

<table>
    <tr>
        <th>序号</th><th>函数原型</th><th>头文件</th><th>说明</th>
    </tr>
    <tr>
        <td>1</td>
        <td>pid_t getpid(void);</td>
        <td>unistd.h</td>
        <td>获取调用进程的进程ID。</td>
    </tr>
    <tr>
        <td>2</td>
        <td>pid_t getppid(void);</td>
        <td>unistd.h</td>
        <td>获取调用进程的父进程ID。</td>
    </tr>
    <tr>
        <td>3</td>
        <td>uid_t getuid(void);</td>
        <td>unistd.h</td>
        <td>获取调用进程的用户ID。</td>
    </tr>
    <tr>
        <td>4</td>
        <td>uid_t geteuid(void);</td>
        <td>unistd.h</td>
        <td>获取调用进程的有效用户ID。</td>
    </tr>
    <tr>
        <td>5</td>
        <td>gid_t getgid(void);</td>
        <td>unistd.h</td>
        <td>获取调用进程的组ID。</td>
    </tr>
    <tr>
        <td>6</td>
        <td>gid_t getegid(void);</td>
        <td>unistd.h</td>
        <td>获取调用进程的有效组ID。</td>
    </tr>
    <tr>
        <td>7</td>
        <td>pid_t fork(void);</td>
        <td>unistd.h</td>
        <td>创建一个新进程。</td>
    </tr>
    <tr>
        <td>序号</td>
        <td>函数原型</td>
        <td>头文件</td>
        <td>说明</td>
    </tr>
</table>