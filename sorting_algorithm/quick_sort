#include <iostream>
#include <algorithm>
const int BUCKET_NUM = 10;
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])



template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
        std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


template <typename T, int len>
int locate(T (&arr)[len], int low, int high)
{
    T value = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= value)
            high--;
        std::swap(arr[high], arr[low]);

        while (low < high && arr[low] <= value)
            low++;
        std::swap(arr[low], arr[high]);
    }
    return low;
}


//递归法
template <typename T, int len>
void sort(T (&arr)[len], int low, int high)
{
    if(low >= high)
        return;
    int mid = locate(arr, low, high);
    sort(arr, low, mid-1);
    sort(arr, mid+1, high);
}



template <typename T, int len>
void quickSortFunc(T (&arr)[len])
{
    std::cout << "=== quick sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);
    sort(arr, 0, len-1);
    printArr(arr);
    
}


/****************************************************************/



struct Range {
    int start, end;
    Range(int s = 0, int e = 0){
        start = s;
        end = e;
    }
};


//迭代法
template <typename T, int len>
void quickSortFunc2(T (&arr)[len])
{
    std::cout << "=== quick sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    if(len <= 0)
        return;

    printArr(arr);
    Range r[len];    //r[]模拟堆栈，p为数量，r[p++]为push，r[--p]为pop
    int p = 0;
    r[p++] = Range(0, len-1);
    while(p){
        Range range = r[--p];
        if (range.start >= range.end)
            continue;

        T mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while(left < right){
            while (left < right && arr[left] < mid) left++;

            while(left < right && arr[right] > mid) right--;
            std::swap(arr[left], arr[right]);
        }

        if(arr[left] >= arr[range.end])
            std::swap(arr[left], arr[range.end]);
        else
            left++;

        r[p++] = Range(range.start, left-1);
        r[p++] = Range(left+1, range.end);
    }
    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    quickSortFunc(data);

    int data2[] = {13, 23, 2, 4, 8, 19, 62, 1};
    quickSortFunc2(data2);

    return 0;
}
