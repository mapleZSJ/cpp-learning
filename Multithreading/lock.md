unique_lock

 对互斥量加锁。 可移动，但不可复制。   <br>
 它满足可移动构造 (MoveConstructible) 和可移动赋值 (MoveAssignable) 但不满足可复制构造 (CopyConstructible) 或可复制赋值 (CopyAssignable) 。

std:unique_lock比std:lock_guard更灵活,这种灵活性主要体现在以下几点:

1.lock_guard在构造时或者构造前(std:adopt_lock)就已经获取 互斥锁,并且在作用域内保持获取锁的状态,直到作用域结束;      <br>
而unique_lock在构造时或者构造后(std:defer_lock)获取锁,在作用域范围内可以手动获取锁和释放锁,作用域结束时如果已经获取锁则自动释放锁。

2.lock_guard锁的持有只能在lock_guard对象的作用域范围内,作用域范围之外锁被释放;     <br>
而unique_lock对象支持移动操作,可以将unique_lock对象通过函数返回值返回,这样锁就转移到外部unique_lock对象中,延长锁的持有时间。'

3.由于unique_lock对象需要根据当前对象是否已经持有锁还是未持有进行判断从而执行适当的操作,因此比lock_guard占用空间稍大一点,效率稍低一点。

std:unique_lock.owns_lock返回当前是否持有锁。通常来说不应该在持有锁的期间执行消耗时间长的操作,此时unique_lock更加灵活,可以随时unlock,避免不相关的操作期间仍然持有锁。
