//错误写法：
//在编译时会产生flexible array member ‘bubbleSort<int>::arrData’ not at end of ‘class bubbleSort<int>’ 的报错
template <typename T>
class bubbleSort
{
private:
    T arrData[];
    int len;

public:
    bubbleSort(T arr[]){
        arrData = arr;
        len = arrLen(arr);
    };
    // bubbleSort(T arr[]):arrData(arr){
    //     len = arrLen(arr);
    // };
}

int main() {
    int data[] = {......};
    bubbleSort<int> bbs(data);
    return 0;
}


/*原因：
flexible array member

C99中，结构中的 最后一个元素 允许是未知大小的数组，这叫做柔性(弹性)数组成员。
但结构中的柔性数组成员前面必须 至少有一个其他成员。柔性数组成员允许结构中包含一个大小可变的数组。
sizeof返回的这种结构大小不包括柔性数组的内存(柔性数组在结构体中不占用空间)。
包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。
*/
