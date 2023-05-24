#include <iostream>
#include <vector>
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])


template <typename T, int n>
class selectionSort
{
private:
    int len;
    std::vector<T> vec;

public:
    selectionSort(T (&arr)[n]):len(n), vec(arr, arr+n)
    {
        std::cout << "=== selection sort class ===" << std::endl;
        std::cout << "array len: " << len << std::endl;
    }

    void sort()
    {
        printArr();
        for (auto i = vec.begin(); i < vec.end() - 1; i++) 
        {
            auto min = i;
            for (auto j = i+1; j < vec.end(); j++)
            {
                if(*j < *min)
                {
                    min = j;
                }
            }
            std::swap(*i, *min);
        }
        printArr();
    }

    void sort2()
    {
        printArr();
        for (int i = 0; i < vec.size() - 1; i++) 
        {
            int min = i;
            for (int j = i+1; j < vec.size(); j++)
            {
                if(vec[j] < vec[min])
                {
                    min = j;
                }
            }
            std::swap(vec[i], vec[min]);
        }
        printArr();
    }

    void printArr()
    {
        for(auto i = vec.begin(); i < vec.end(); i++)
                std::cout<< *i << " ";   // std::cout << vec.at(i) << " ";
        std::cout << std::endl;
    }

    ~ selectionSort(){}
};


/****************************************************************/


template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
            std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


template <typename T, int len>
void selectionSortFunc(T (&arr)[len])
{
    std::cout << "=== selection sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    for (int i = 0; i < len - 1; i++) 
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19};
    selectionSortFunc(data);
    
    int data2[] = {13, 23, 2, 4, 8, 62, 19};
    selectionSort<int, ARR_LENGTH(data2)> ss(data2);
    ss.sort();

    return 0;
}
