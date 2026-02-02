序列容器：   <br>
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



排序容器(关联式容器)：红黑树   键值对、根据键值的大小做升序排序，内存不连续；查找、插入、删除，O(1)。   <br>
[注：pair类模版，定义在<utility>头文件中，创建键值对。  pair<std::string, std::string> pair1(key, value)]
map：键是唯一的，不能重复。元素根据元素键的大小做升序排序（std::less<T>）。键值对一旦被存入容器中，键不能重复也不能修改。
     std::map<std::string, int> myMap{{"myMap1", 10}, {"myMap2", 20}};

multimap：与map相同，但是键可以重复。
          std::multimap<std::string, int> myMultimap{{"myMultimap1", 10}, {"myMultimap2", 20}};

set：各个元素键和值完全相同，各个元素的值不能重复，不能修改元素的值，元素根据元素键的大小做升序排序（std::less<T>）。只能用迭代器访问。
     std::set<std::string> mySet{"myset1", "myset2"};


multiset：与set相同，但是值可以重复。
          std::multiset<std::string> myMultiset{"myMultiset1", "myMultiset2"};



哈希容器(非关联式容器)：哈希表   无序键值对，擅长通过键查找对应的值，O(1)；而遍历容器中存储元素的效率不如关联式容器。  <br>
[注：采用哈希表实现无序容器时，会将所有数据存储到一整块连续的内存空间中，当存储位置发生冲突时，解决方法选用的是链地址法(开链法)]
unordered_map：无序，各个元素的键不能重复也不能修改。
               std::unordered_map<std::string, int> umap{{"umap1", 10}, {"umap2", 20}};
               [注：在操作容器的过程中，如添加键值对，一旦容器的负载因子超过最大负载因子(默认1.0)，容器就会适当增加桶(本质是链表)的数量(通常是翻一倍)，并自动执行rehash()，重新调整各个键值对的存储位置（这个过程又称"重哈希"）。此过程很可能会导致之前的迭代器失效，失效针对的是表示容器内某个范围的迭代器，不会影响指向单个键值对的迭代器。]

unordered_multimap：与unordered_map相同，但是允许存储多个键相同的键值对。
                    std::unordered_multimap<std::string, int> ummap{{"ummap1", 10}, {"ummap2", 20}};

unordered_set：无序，各个元素键和值完全相同，各个元素的值不能重复，不能修改元素的值。
               std::unordered_set<std::string> uset{"uset1", "uset2"};

unordered_multiset：与unordered_set相同，允许存储值相同的元素，且这些元素会存储到哈希表中同一个桶(本质是链表)上。
                    std::unordered_multiset<std::string> umset{"umset1", "umset2"};



容器适配器：封装了序列容器的类模板       <br>
stack<T>：封装了deque<T>容器的适配器类模板，定义在头文件<stack>中，后入先出。
          [满足条件的基础容器有 vector、deque、list]
          std::stack<int> values{1, 2, 3};
          std:stack<int, std::list<int>> mystack;

queue<T>：封装了deque<T>容器的适配器类模板，定义在头文件<queue>中，先入先出。
          [满足条件的基础容器有 deque、list]
          std::queue<int> values{1, 2, 3};
          std::queue<int, std::list<int>> myqueue;

priority_queue<T>：封装了vector<T>容器的适配器类模板，定义在头文件<queue>中，默认实现是一个会对元素排序，保证最大元素总在队列最前面的队列。从一端进(队尾)，从另一端出(队头)，且每次只能访问位于队头的元素。在创建时制定了一种排序规则（std::less<T>），优先级最大的元素最先出队列。
                   [注：为了保证每次从队头移除的都是当前优先级最高的元素，每当有新元素进入或从队头移除一个元素后，它都会根据既定的排序规则找到优先级最高的元素，并将其移动到队列的队头]
                   [满足条件的基础容器有 vector、deque]；底层是堆结构
                   std::priority_queue<int> values;
                   std::priority_queue<int, std::deque<int>> mupqueue;



tip：
1、analyse std::vector<bool> design    <br>
source link --> https://zhuanlan.zhihu.com/p/376377479

std::vector<bool>，是类 sd::vector<T,std::allocator<T>> 的部分特化，为了节省内存，内部实际上是按bit来表征bool类型。从底层实现来看，std::vector<bool> 可视为动态的std::bitset.


_Bit_type:
In C++ standard, GNU-STL use typedef to define unsigned long as _Bit_type. a _Bit_type has 64bit，can store 64 bool type variables.


typedef unsigned long _Bit_type;  // _Bit_type
enum
{
  _S_word_bit = int(__CHAR_BIT__ * sizeof(_Bit_type)) // a _Bit_type can store _S_word_bit bits
};













