#include <iostream>
#include <algorithm>
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])



template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
        std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


template <typename T, int len>
void maxHeapify(T (&arr)[len], int start, int end){
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {
        if(son+1 <= end && arr[son] < arr[son+1])   //先比较两个子节点大小，选最大的
            son++;

        if(arr[dad] > arr[son])   //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else{                     //否则交换父子内容再继续子节点和孙节点比较
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
    
}



template <typename T, int len>
void heapSortFunc(T (&arr)[len])
{
    std::cout << "=== heap sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    //初始化，i从最后一个父节点(len/2-1)开始调整
    for(int i=len/2-1; i >= 0; i--)
        maxHeapify(arr, i, len - 1);    //把最大值调到堆顶(arr[0])
    
    //先将第一个元素和已经排好的元素前一位做交换，再重新调整(刚调整的元素之前的元素)，直到排序完毕
    for(int i=len-1; i > 0; i--){
        std::swap(arr[0], arr[i]);      //堆顶最大值和堆尾互换，每次都会确认一个元素(最大值)的位置
        maxHeapify(arr, 0, i-1);        //从堆顶开始，把最大值调到堆顶(arr[0])
    }

    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    heapSortFunc(data);
    
    return 0;
}
