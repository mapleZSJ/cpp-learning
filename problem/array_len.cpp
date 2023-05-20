//函数中使用sizeof(arr) / sizeof(arr[0])求数组长度不正确

//错误用法：
template <typename T>
int arrLen(T& arr){
    return sizeof(arr)/sizeof(arr[0]);
}


/*
原因：
sizeof()函数是求数组所占的内存空间大小（不是长度）。当在函数中使用该方法求数组长度时，由于数组作为函数参数传入函数的过程中会“退化”为指针，
因此将会导致sizeof(arr)求出的是一个指针的内存空间大小，而非数组的内存空间大小–>从而导致计算的长度错误。
*/



/*
解决方法：
1.使用宏定义
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])


2.先计算数组长度，然后将数组长度作为函数参数与数组一起传入
int len = sizeof(arr)/sizeof(arr[0]);
sort(arr, len);


3.利用模板传递参数
template <size_t N>
void print(int (&array)[N]) // 利用模板传递参数 array是数组的引用
{
    for (size_t i = 0;i < N;i ++) {
        //...
    }
}

template <typename T, size_t N>
void print2(T (&array)[N])
{    
    for (size_t i = 0;i < N;i ++) {
        //...
    }
}

int main()
{
    int arr[] = {...};
    print(arr);
    print2(arr);
}
*/
