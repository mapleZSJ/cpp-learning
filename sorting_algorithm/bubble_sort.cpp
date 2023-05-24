#include <iostream>
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])


template <typename T>
class bubbleSort
{
private:
    int len;

public:
    bubbleSort(T& arrData)
    {
        std::cout << "=== bubble sort class ===" << std::endl;
        len = ARR_LENGTH(arrData);
        std::cout << "array len: " << len << std::endl;
    }

    void sort(T& arrData)
    {
        printArr(arrData);
        for (int i = 0; i < len - 1; i++) 
        {
            for (int j = 0; j < len - 1; j++)
            {
                if(arrData[j] > arrData[j+1])
                {
                    std::swap(arrData[j], arrData[j+1]);
                }
            }
        }
        printArr(arrData);

    }

    void printArr(T& arrData)
    {
        for(int i = 0; i < len; i++)
                std::cout<< arrData[i] << " ";
        std::cout << std::endl;
    }

    ~ bubbleSort(){}
};


/****************************************************************/


template <typename T, int n>
class bubbleSort2
{
private:
    int len;
    T arrData[n];

public:
    bubbleSort2(T (&arr)[n]):len(n)
    {
        std::cout << "=== bubble sort2 class ===" << std::endl;
        std::cout << "array len: " << n << std::endl;
        for(int i = 0; i < len; i++)
        {
            arrData[i] = arr[i];
            std::cout<< arrData[i] << " ";
        }
        std::cout << std::endl;
    }

    void sort()
    {
        for (int i = 0; i < len - 1; i++) 
        {
            for (int j = 0; j < len - 1; j++)
            {
                if(arrData[j] > arrData[j+1])
                {
                    std::swap(arrData[j], arrData[j+1]);
                }
            }
        }
        printArr();

    }

    
    void printArr()
    {
        for(int i = 0; i < len; i++)
                std::cout<< arrData[i] << " ";
        std::cout << std::endl;
    }

    ~ bubbleSort2(){}
};


/****************************************************************/


template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
            std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


template <typename T, int len>
void bubbleSortFunc(T (&arr)[len])
{
    std::cout << "=== bubble sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    for (int i = 0; i < len - 1; i++) 
    {
        for (int j = 0; j < len - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 19, 54};
    bubbleSortFunc(data);
    
    int data2[] = {13, 23, 2, 4, 8, 19, 62};
    bubbleSort<decltype(data2)> bbs(data2);
    bbs.sort(data2);

    int data3[] = {13, 23, 2, 4, 8, 19, 88};
    const int len3 = std::end(data3) - std::begin(data3);
    bubbleSort2<int, len3> bbs2(data3);
    bbs2.sort();

    return 0;
}
