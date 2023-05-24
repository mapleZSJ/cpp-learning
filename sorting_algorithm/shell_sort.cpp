#include <iostream>
#include <vector>



template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
            std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


template <typename T, int len>
void shellSortFunc(T (&arr)[len])
{
    std::cout << "=== insertion sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    int h = 1;
    while (h < len / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for(int i = h; i < len; i++) {
            for(int j=i; j >= h && arr[j] < arr[j-h]; j-=h){
                std::swap(arr[j], arr[j-h]);
            }
        }
        h = h/3;
    }

    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    shellSortFunc(data);
    
    return 0;
}
