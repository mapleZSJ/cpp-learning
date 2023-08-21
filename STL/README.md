序列容器：
array：静态数组，大小固定、无法动态扩散或收缩。
       底层是数组，元素都存储在连续的内存空间中。
       std::array<int, 10> values {};

vector：动态数组，动态调整所占用的内存空间。在尾部插入/删除，O(1)；在头部或中部插入/删除，O(n)。
        底层是数组(线性表)，元素都存储在连续的内存空间中。
        std::vector<int> values;
        [*注：vector<bool>不是存储bool类型元素的vector容器]

deque：是double-ended queue的缩写，又称双端队列容器。可以修改自身容量、大小，在头部或尾部插入/删除，O(1)；在中部插入/删除，O(n)。
       底层是堆+指针，存储元素并不能保证所有元素都存储到连续的内存空间中。
       std::deque<int> values;

list：双向链表容器，不能通过位置直接访问元素，需要遍历容器。在任何已知的位置插入/删除，O(1)；查找O(n)。
      底层是双向链表，元素是分散存储在内存空间里。
      std::list<int> values;

forward_list：单链表容器，不能通过位置直接访问元素，需要遍历容器。在任何已知的位置插入/删除，O(1)；查找O(n)。
              底层是单链表，元素是分散存储在内存空间里。
              std::forward_list<int> values;