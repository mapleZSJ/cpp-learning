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
void countingSortFunc(T (&arr)[len])
{
    std::cout << "=== counting sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    int countNum = *std::max_element(arr, arr+len) + 1;
    T sortArr[len] = {};
    T countArr[countNum] = {};
    int i;
    for(i=0; i < countNum; i++)
        countArr[i] = 0;

    for(i=0; i < len; i++)
        countArr[arr[i]]++;    //统计arr各个元素出现的次数

    for(i=1; i < countNum; i++)
        countArr[i] += countArr[i-1];   //合计元素排序后应出现的位置

    for(i=len; i > 0; i--)
        sortArr[--countArr[arr[i-1]]] = arr[i-1];

    printArr(sortArr);
}



int main() {

    int data[] = {11, 4, 2, 4, 8, 14, 10, 1};
    countingSortFunc(data);
    
    return 0;
}
