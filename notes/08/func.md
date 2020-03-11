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
        <td>8</td>
        <td>pid_t vfork(void);</td>
        <td>unistd.h</td>
        <td>创建一个新进程。</td>
    </tr>
    <tr>
        <td>9</td>
        <td>void exit(int status);</td>
        <td>stdlib.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>10</td>
        <td>pid_t wait(int *status);</td>
        <td>sys/wait.h</td>
        <td>获取子进程的终止状态。</td>
    </tr>
    <tr>
        <td>11</td>
        <td>pid_t waitpid(pid_t pid, int *status, int options);</td>
        <td>sys/wait.h</td>
        <td>获取子进程的终止状态。</td>
    </tr>
    <tr>
        <td>12</td>
        <td>int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);</td>
        <td>sys/wait.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>13</td>
        <td>pid_t wait3(int *status, int options, struct rusage *rusage);</td>
        <td>sys/types.h<br>
            sys/wait.><br>
            sys/time.h<br>
            sys/resource.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>14</td>
        <td>pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);</td>
        <td>sys/types.h<br>
            sys/wait.><br>
            sys/time.h<br>
            sys/resource.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>15</td>
        <td>int execl(const char *pathname, const char *arg0, ... /* (char*)0 */);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>16</td>
        <td>int execv(const char *pathname, char *const argv[]);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>17</td>
        <td>int execle(const char *pathname, const char *arg, ... /* (char *)0, char *const envp[] */);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>18</td>
        <td>int execve(const char *pathname, char *const argv[], char *const envp[]);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>19</td>
        <td>int execlp(const char *filename, const char *arg0, ... /* (char*)0 */);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>20</td>
        <td>int execvp(const char *filename, char *const argv[]);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>21</td>
        <td>int fexecve(int fd, char *const argv[], char *const envp[]);</td>
        <td>unistd.h</td>
        <td>/</td>
    </tr>
    <tr>
        <td>序号</td>
        <td>函数原型</td>
        <td>头文件</td>
        <td>说明</td>
    </tr>
</table>