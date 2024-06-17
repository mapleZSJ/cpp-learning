## std::unique_lock

 对互斥量加锁。 可移动，但不可复制。   <br>
 它满足可移动构造 (MoveConstructible) 和可移动赋值 (MoveAssignable) 但不满足可复制构造 (CopyConstructible) 或可复制赋值 (CopyAssignable) 。

std::unique_lock比std::lock_guard更灵活,这种灵活性主要体现在以下几点:

1.lock_guard在构造时或者构造前(std::adopt_lock)就已经获取 互斥锁,并且在作用域内保持获取锁的状态,直到作用域结束;      <br>
而unique_lock在构造时或者构造后(std::defer_lock)获取锁,在作用域范围内可以手动获取锁和释放锁,作用域结束时如果已经获取锁则自动释放锁。

2.lock_guard锁的持有只能在lock_guard对象的作用域范围内,作用域范围之外锁被释放;     <br>
而unique_lock对象支持移动操作,可以将unique_lock对象通过函数返回值返回,这样锁就转移到外部unique_lock对象中,延长锁的持有时间。'

3.由于unique_lock对象需要根据当前对象是否已经持有锁还是未持有进行判断从而执行适当的操作,因此比lock_guard占用空间稍大一点,效率稍低一点。

std::unique_lock.owns_lock返回当前是否持有锁。通常来说不应该在持有锁的期间执行消耗时间长的操作,此时unique_lock更加灵活,可以随时unlock,避免不相关的操作期间仍然持有锁。


<br>


## std::condition_variable
读写锁把对共享资源的访问者划分成读者和写者,读者只对共享资源进行读访问,写者则需要对共享资源进行写操作。C++17开始,标准库提供了shared_mutex类(在这之前,可以使用boost的shared_mutex类或系统
相关api)。

和其他便于独占访问的互斥类型不同，shared_mutex拥有两个访问级别:   <br>
共享：多个线程能共享同一互斥的所有权（如配合shared_lock）；
独占：仅有一个线程能占有互斥（如配合lock_guard、unique_lock）。

shared_mutex通常用于多个读线程能同时访问同一资源而不导致数据竞争,但只有一个写线程能访问的情形。


<br>


## std::condition_variable

std::condition_variable 是条件变量, Linux下使用Pthread 库中的pthread_cond _* ()函数提供了与条件变量相关的功能

当std::condition_variable 对象的某个**wait函数**被调用的时候,它使用std::unique_lock(通过std::mutex)来锁住当前线程。当前线程会一直被阻塞,直到另外一个线程在相同的std::condition_variable对象上调用了**notification函数**来唤醒当前线程。

std::condition_variable对象通常使用std::unique_lock<std.mutex>来等待,如果需要使用另外的lockable类型,可以使用std::condition_variable_any类。

**std::condition_variable::wait()**  <br>
```
std:condition_variable提供了两种wait()函数:
void wait(unique_lock<mutex>& lck);
当前线程调用wait()后将被阻塞(此时当前线程应该获得了锁lck(mutex)),直到另外某个线程调用notify _* 唤醒了当前线程,该函数会自动调用lck.unlock() 释放锁,使得其他被阻塞在锁竞争上的线程得以继续执行。

template <class Predicate>
void wait (unique_lock<mutex>& lck, Predicate pred);
若设置了Predicate,只有当pred条件为false时调用wait()才会阻塞当前线程,并且在收到其他线程的通知后只有当pred为true时才会被解除阻塞。
代码如下：
while (!pred())
    wait(lck);

```

**std::condition_variable::wait_for()**    <br>
与std::condition_variable:wait()类似,不过wait_for可以指定一个**时间段**,在当前线程收到通知或者指定的时间rel_time超时之前,该线程都会处于阻塞状态。而一旦超时或者收到了其他线程的通知,wait_for返回,剩下的处理步骤和wait()类似。

另外,wait_for的重载版本(predicte(2))的最后一个参数pred表示wait_for的预测条件,只有当pred条件为false时调用wait()才会阻塞当前线程,并且在收到其他线程的通知后只有当pred为true时才会被解除阻塞。


**std::condition_variable::wait_until()**    <br>
与std::condition_variable::wait_for类似,但是wait_until可以指定一个**时间点**,在当前线程收到通知或者指定的时间点abs_time超时之前,该线程都会处于阻塞状态。而一旦超时或者收到了其他线程的通知,wait_until返回,剩下的处理步骤和wait()类似。

另外,wait_until的重载版本(predicte(2))的最后一个参数pred表示wait_until的预测条件,只有当pred 条件为false时调用wait()才会阻塞当前线程,并且在收到其他线程的通知后只有当pred 为true时才会被解除阻塞。


**std::condition_variable::notify_one()**    <br>
唤醒某个等待(wait)线程。如果当前没有等待线程,则该函数什么也不做,如果同时存在多个等待线程,则唤醒某个线程是不确定的(unspecified)。


**std::condition_variable::notify_all()**     <br>
唤醒所有的等待(wait)线程。如果当前没有等待线程,则该函数什么也不做。


**std::condition_variable_any()**     <br>
与std::condition_variable类似,只不过std::condition_variable_any的wait函数可以接受任何 lockable 参数,而std::condition_variable只能接受 std::unique_lock<std::mutex>类型的参数,除此以外,和std::condition_variable 几乎完全一样。


**std::cv_status**  枚举类型   <br>
cv_status::no_timeout  wait_for或者wait_until没有超时,即在规定的时间段内线程收到了通知。   <br>
cv_status::timeout  wait_for或者 wait_until超时。    <br>


**std::notify_all_at_thread_exit**   <br>
当调用该函数的线程退出时，所有在cond条件变量上等到的线程都会收到通知。





