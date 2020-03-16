<h1 id=file_readme>
    《UNIX环境高级编程》笔记
</h1>

> 简介
> 待填坑

<h2 id=title_ch01>
    <a href="notes/01/notes.md">
        第01章 UNIX基础知识
    </a>
</h2>

> 本章从程序员的角度快速浏览`UNIX`，对书中引用的一些术语和概念进行简要的说明并给出示例。在以后的示例中，将对这些概念做更详细的说明。对于初涉UNIX环境的程序员，本章还简要介绍了`UNIX`提供的各种服务。

<h2 id=title_ch02>
    <a href="notes/02/notes.md">
        第02章 UNIX标准及实现
    </a>
</h2>

> 本章首先回顾过去`25`年人们在`UNIX`标准化方面做出的种种努力，然后讨论这些`UNIX`编程标准对本书所列举的各种UNIX操作系统实现的影响。所有标准化工作的一个重要部分是对每种实现必须定义的各种限制进行说明，所以我们将说明这些限制以及确定它们值得各种方法。

<h2 id=title_ch03>
    <a href="notes/03/notes.md">
        第03章 文件I/O
    </a>
</h2>

> 本章开始讨论`UNIX`系统，说明可用的文件`I/O`函数————打开文件、读文件、写文件等。`UNIX`系统中的大多数文件`I/O`只需用到`5`个函数：`open`、`read`、`write`、`lseek`以及`close`。然后说明不同缓冲长度对`read`和`write`函数的影响。

<h2 id=title_ch04>
    <a href="notes/04/notes.md">
        第04章 文件和目录
    </a>
</h2>

> 本章将描述文件系统的其他特性和文件的性质。我们将从`stat`函数开始，逐个说明`stat`结构的每一个成员以了解文件的所有属性。

<h2 id=title_ch05>
    <a href="notes/05/notes.md">
        第05章 标准I/O库
    </a>
</h2>

> 简介

<h2 id=title_ch07>
    <a href="notes/07/notes.md">
        第07章 进程环境
    </a>
</h2>

> 本章中将学习：当程序执行时，其main函数是如何被调用的；命令行参数是如何传递给新程序的；典型的存储空间布局是什么样式；如何分配另外的存储空间；进程如何使用环境变量；进程的各种不同终止方式等。另外，还将说明longjmp和setjmp函数以及它们与栈的交互作用。本章结束之前，还将查看进程的资源限制。

<h2 id=title_ch08>
    <a href="notes/08/notes.md">
        第08章 进程控制
    </a>
</h2>

> 本章介绍UNIX系统的进程控制，包括创建新进程、执行程序和进程终止。

<h2 id=title_ch09>
    <a href="notes/09/notes.md">
        第09章 进程关系
    </a>
</h2>

> 本章将更详细地说明进程组以及POSIX.1引入的会话的概念。还将介绍登录shell（登录时所调用的）和所有从登录shell启动的进程之间的关系。

<h2 id=title_layout_err>
    <a href="notes/layout_err.md">
        排版错误记录
    </a>
</h2>