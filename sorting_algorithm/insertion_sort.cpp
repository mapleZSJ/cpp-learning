#include <iostream>
#include <vector>
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])


template <typename T, int n>
class insertionSort
{
private:
    int len;
    std::vector<T> vec;

public:
    insertionSort(T (&arr)[n]):len(n), vec(arr, arr+n)
    {
        std::cout << "=== insertion sort class ===" << std::endl;
        std::cout << "array len: " << len << std::endl;
    }

    void sort()
    {
        printArr();
        for (auto i = vec.begin() + 1; i < vec.end(); i++) 
        {
            for (auto j = i-1; j >= vec.begin(); j--)
            {
                if(*j > *(j+1))
                {
                    std::swap(*j, *(j+1));
                }else {
                    break;
                }
            }
        }
        printArr();
    }

    void sort2()
    {
        printArr();
        for (int i = 1; i < vec.size(); i++) 
        {
            T key = vec[i];
            int j = i-1;
            while ((j >= 0) && (key < vec[j]))
            {
                vec[j+1] = vec[j];
                j--;
            }
            vec[j+1] = key;
            
        }
        printArr();
    }

    void printArr()
    {
        for(auto i = vec.begin(); i < vec.end(); i++)
                std::cout<< *i << " ";   // std::cout << vec.at(i) << " ";
        std::cout << std::endl;
    }

    ~ insertionSort(){}
};


/****************************************************************/


template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
            std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


template <typename T, int len>
void insertionSortFunc(T (&arr)[len])
{
    std::cout << "=== insertion sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    for (int i = 1; i < len ; i++) 
    {
        for (int j = i-1; j >= 0; j--)
        {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
            else {
                break;
            }
        }
    }
    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    insertionSortFunc(data);
    std::cout << std::endl;
    
    int data2[] = {13, 23, 2, 4, 8, 62, 19, 1};
    insertionSort<int, ARR_LENGTH(data2)> iss(data2);
    iss.sort();

    return 0;
}
