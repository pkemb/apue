<h1 id=file_func>
    第11章 线程
</h1>

[章节目录](../../README.md#title_ch11 "返回章节目录")
[笔记](notes.md "进入笔记")

---

<table>
    <tr>
        <th>序号</th><th>函数原型</th><th>头文件</th><th>说明</th>
    </tr>
    <tr>
        <td>1</td>
        <td>int pthread_equal(pthread_t tid1, pthread_t tid2);</td>
        <td>pthread.h</td>
        <td>比较两个线程ID是否相等</td>
    </tr>
    <tr>
        <td>2</td>
        <td>pthread_t pthread_self(void);</td>
        <td>pthread.h</td>
        <td>获取调用线程的线程ID。</td>
    </tr>
    <tr>
        <td>3</td>
        <td>int pthread_create(pthread_t *tidp,<br>
            const pthred_attr_t *attr,<br>
            void *(*start_rtn)(void*),<br>
            void *arg);</td>
        <td>pthread.h</td>
        <td>创建一个新线程。</td>
    </tr>
    <tr>
        <td>4</td>
        <td>int pthread_exit(void *rval_ptr);</td>
        <td>pthread.h</td>
        <td>退出线程。</td>
    </tr>
    <tr>
        <td>5</td>
        <td>int pthread_join(pthread_t tid, void **rval_ptr);</td>
        <td>pthread.h</td>
        <td>获取线程的退出状态。</td>
    </tr>
    <tr>
        <td>6</td>
        <td>int pthread_cancel(pthread_t tid);</td>
        <td>pthread.h</td>
        <td>请求取消线程。</td>
    </tr>
    <tr>
        <td>7</td>
        <td>void pthread_clenup_push(void (*rtn)(void*), void *arg);</td>
        <td>pthread.h</td>
        <td>注册线程清理处理程序。</td>
    </tr>
    <tr>
        <td>8</td>
        <td>void pthread_cleanup_pop(int execute);</td>
        <td>pthread.h</td>
        <td>删除线程清理处理程序。</td>
    </tr>
    <tr>
        <td>9</td>
        <td>int pthread_detach(pthread_t tid);</td>
        <td>pthread.h</td>
        <td>分离线程。</td>
    </tr>
    <tr>
        <td>序号</td>
        <td>函数原型</td>
        <td>头文件</td>
        <td>说明</td>
    </tr>
</table>