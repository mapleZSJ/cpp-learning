序列容器：  <br>
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


排序容器(关联式容器)：红黑树  键值对、根据键值的大小做升序排序；查找、插入、删除，O(1)。
[注：pair类模版，定义在<utility>头文件中，创建键值对。  pair<std::string, std::string> pair1(key, value)]
map：键是唯一的，不能重复。元素根据元素键的大小做升序排序（std::less<T>）。键值对一旦被存入容器中，键不能重复也不能修改。
     std::map<std::string, int> myMap{{"myMap1", 10}};

multimap：与map相同，但是键可以重复。
          std::multimap<std::string, int> myMultimap{{"myMultimap1", 10}};

set：各个元素键和值完全相同，各个元素的值不能重复，不能修改元素的值，元素根据元素键的大小做升序排序std::less<T>）。只能用迭代器访问。
     std::set<std::string> mySet{"myset1", "myset2"};


multiset：与set相同，但是值可以重复。
          std::multiset<std::string> myMultiset{"myMultiset1", "myMultiset2"};



哈希容器(非关联式容器)：哈希表







