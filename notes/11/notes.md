<h1 id=file_notes>
    第11章 线程
</h1>

[章节目录](../../README.md#title_ch11 "返回章节目录")
[函数表](func.md "进入函数表")

---

<h2 id=ch_11.2>
    线程概念
</h2>

* 典型的UNIX进程可以看做只有一个控制线程。
* 多个控制线程可以使进程在同一时刻完成多件事情。

引入线程的优点：
* 简化处理异步事件的代码。
* 进程之间的共享非常复杂，而线程之间可以自动共享某些数据。
* 提供整个程序的吞吐量。
* 改善响应时间。

注意：多线程与多处理器/多核没有必然的联系，单核处理器也可以提供多线程。

线程执行环境所必须的信息：
* 线程ID
* 一组寄存器值
* 栈
* 调度优先级和策略
* 信号屏蔽字
* errno变量
* 线程私有数据

进程的所有信息对该进程的所有线程都是共享的，包括
* 可执行程序代码
* 程序的全局变量
* 堆内存
* 栈
* 文件描述符

线程接口
* 也称为`pthread`，或`POSIX线程`
* 测试宏：_POSIX_THREAD

<h2 id=ch_11.3>
    线程标识
</h2>

线程ID：tid
* 只在线程所属进程的上下文中才有意义。
* 数据类型：`pthread_t`
* `pthread_t`可能是结构，或者是整数，取决于实现。
* 没有一种可移植的方式打印线程ID。

```c
int pthread_equal(pthread_t tid1, pthread_t tid2);
功能：比较两个线程ID是否相等。
头文件：pthread.h
返回值：相等返回非0数值，否则返回0。

pthread_t pthread_self(void);
功能：获取自身的线程ID。
头文件：pthread.h
返回值：调用线程的线程ID。
```

<h2 id=ch_11.4>
    线程创建
</h2>

在创建多个线程之前，程序的行为与传统的进程并没有什么区别。

```c
int pthread_create(pthrad_t *tidp,
                   const pthreat_attr_t *attr,
                   void *(*start_rtn)(void*), 
                   void *arg);
功能：创建一个新的线程。
头文件：pthread.h
返回值：成功返回0，出错返回错误编号。
形参说明：
    tidp: 新创建线程的线程ID（成功返回时）。
    attr：设置线程各种不同的属性。如果为NULL，则属性去默认值。
    start_rtn：线程运行的函数，此函数只有一个无类型指针参数。
    arg：传递给线程运行函数的参数。
```

注：
* 如果需要传递一个以上的参数，需要将参数放入到一个结构中。
* 新创建线程和现有线程的运行顺序是不确定的。
* 新线程会继承调用线程的浮点环境和信号屏蔽字，但挂起信号集会被清除。
* 每个线程都会提供errno的副本，与使用errno的现有函数兼容。
* pthread函数在调用失败时通常返回errno。
* Linux2.4使用单独的进程实现每个线程，很难与POSIX线程的行为匹配。
* Linux2.6使用Native POSIX线程库（NPTL），支持单进程中有多个线程的模型。


<h2 id=ch_11.5>
    线程终止
</h2>

与进程终止的关系：
* 进程中的任意线程调用了exit、_Exit、_exit，则整个进程终止。
* 如果信号的默认动作是终止进程，则发送到线程的信号会终止进程。

单个线程在不终止进程的情况下退出：
* 从启动例程返回，返回值是线程的退出码。
* 被同一进程的其他线程取消。
* 调用pthread_exit。

```c
void pthread_exit(void *rval_ptr);
头文件：pthread.h
功能：终止线程的控制流。

void pthread_join(void **rval_ptr);
功能：获取指定线程的返回值，或传递给pthread_exit的参数。
返回值：成功返回0，出错返回错误编号。
rval_ptr：可以为空，这样只等待指定线程退出，不获取进程的终止状态。
```

注：
* pthread_join会让调用进程阻塞，知道指定进程退出或被取消。
* 如果线程被取消，rval_ptr指定的内存单位被设置为PTHREAD_CANCELED。
* pthread_exit传递一个复杂的结构体，要保证函数返回后结构体所用内存依旧有效。
> 可以使用malloc或全局变量来保证内存依旧有效。

```c
int pthread_cancel(pthread_t tid);
功能：请求取消同一进程中的其他线程。并不等待线程终止，仅仅提出请求。
返回值：成功返回0，出错返回错误编号。
等同于pthread_exit(tid, (void*)PTHREAD_CANCELED);
```

```c
void pthread_cleanup_push(void (*rtn)(void*), void *arg);
功能：注册线程清理处理程序，可以注册多个。执行顺序与注册顺序相反。

void pthread_cleanup_pop(int execute);
功能：删除上次pthread_cleanup_push建立的清理处理程序。
     如果execute为0，则清理处理程序不被调用。
```

注：
* 清理处理程序调用的时机：
  * 调用pthread_exit时
  * 响应取消请求时
  * 用非0参数调用pthread_cleanup_pop时
* 这两个函数可能实现为宏，所以必须在与线程相同的作用域中以匹配对的形式使用。

```c
int pthread_detach(pthread_t tid);
功能：分离线程，使线程处于分离状态。
返回值：成功返回0，出错返回-1。

通常情况下，线程的终止状态会保存直到对该线程调用pthread_join。
分离状态下，线程终止时会立即回收线程的底层存储资源。
分离状态下对线程调用pthread_join的行为是未定义的。
```

进程控制原语与线程控制原语的比较：

<table>
    <tr><th>进程原语</th><th>线程原语</th><th>描述</th></tr>
    <tr>
        <td>fork</td>
        <td>pthread_create</td>
        <td>创建新的控制流</td>
    </tr>
    <tr>
        <td>exit</td>
        <td>pthread_exit</td>
        <td>从现有的控制流退出</td>
    </tr>
    <tr>
        <td>waitpid</td>
        <td>pthread_join</td>
        <td>从控制流中得到退出状态</td>
    </tr>
    <tr>
        <td>atexit</td>
        <td>pthread_cleanup_push</td>
        <td>注册在退出控制流时调用的函数</td>
    </tr>
    <tr>
        <td>getpid</td>
        <td>pthread_self</td>
        <td>获取控制流的ID</td>
    </tr>
    <tr>
        <td>abort</td>
        <td>pthread_cancel</td>
        <td>请求控制流的非正常退出</td>
    </tr>
</table>

---

[章节目录](../../README.md#title_ch11 "返回章节目录")
[函数表](func.md "进入函数表")