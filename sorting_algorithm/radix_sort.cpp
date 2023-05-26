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
int maxBit(T (&arr)[len])
{
    int d = 1;
    int p = 10;
    T maxData = *std::max_element(arr, arr+len);
    while (maxData >= p)
    {
        maxData /= p;
        ++d;
    }
    return d;
}



template <typename T, int len>
void radixSortFunc(T (&arr)[len])
{
    std::cout << "=== radix sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    int d =  maxBit(arr);
    T *tmp = new T[len];
    int *count = new int[BUCKET_NUM];
    int i, j, k;
    int radix = 1;
    for(i=1; i <= d; i++)
    {
        for(j=0; j < BUCKET_NUM; j++)
            count[j] = 0;

        for(j=0; j < len; j++){
            k = (arr[j] / radix) % 10;   //统计每个桶中某位数相同的元素的个数
            count[k]++;
        }

        for(j=1; j < BUCKET_NUM; j++)
            count[j] = count[j-1] + count[j];   //将tmp中的位置依次分配给每个桶（合计元素所在位置）

        for(j=len-1; j >= 0; j--){       //从后往前将所有桶中记录依次收集到tmp中
            k = (arr[j] / radix) % 10;
            tmp[--count[k]] = arr[j];
        }

        for(j=0; j < len; j++)
            arr[j] = tmp[j];
        
        radix = radix*10;
    }

    delete []tmp;
    delete []count;
    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    radixSortFunc(data);
    
    return 0;
}
