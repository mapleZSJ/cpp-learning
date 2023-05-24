#include <iostream>
#include <vector>
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])


template <typename T, int n>
class mergeSort
{
private:
    int len;
    std::vector<T> vec;

public:
    mergeSort(T (&arr)[n]):len(n), vec(arr, arr+n)
    {
        std::cout << "=== merge sort class ===" << std::endl;
        std::cout << "array len: " << len << std::endl;
        printArr();
    }

    //递归版
    void sort(int front, int end)
    {
        if (front >= end)
            return;
        int mid = (front + end) / 2;
        sort(front, mid);
        sort(mid+1, end);
        merge(front, mid, end);
    }

    void merge(int front, int mid, int end){
        
        auto end_it = vec.end() != (vec.begin() + end) ? vec.begin() + end + 1 : vec.begin() + end;
        std::vector<T> leftSubArr(vec.begin() + front, vec.begin() + mid + 1);
        std::vector<T> rightSubArr(vec.begin() + mid + 1, end_it);
        int idxLeft = 0, idxRight = 0;

        for (int i=front; i <= end; i++){
            if( idxRight >= rightSubArr.size() || ((idxLeft < leftSubArr.size()) && (leftSubArr[idxLeft] < rightSubArr[idxRight]))){
                vec[i] = leftSubArr[idxLeft];
                idxLeft++;
            }else{
                vec[i] = rightSubArr[idxRight];
                idxRight++;
            }
        }
    }

    void printArr()
    {
        for(auto i = vec.begin(); i < vec.end(); i++)
                std::cout<< *i << " ";   // std::cout << vec.at(i) << " ";
        std::cout << std::endl;
    }

    ~ mergeSort(){
        printArr();
    }
};


/****************************************************************/


template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
            std::cout<< arr[i] << " ";
    std::cout << std::endl;
}


//迭代版
template <typename T, int len>
void mergeSortFunc(T (&arr)[len])
{
    std::cout << "=== merge sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    T *a = arr;
    T *b = new T[len];
    for (int i = 1; i < len; i += i){
        for(int start=0; start < len; start += 2*i){
            int low = start, mid = std::min(start+i, len), high = std::min(start + 2*i, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while(start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];

            while (start1 < end1)
                b[k++] = a[start1++];

            while (start2 < end2)
                b[k++] = a[start2++];
            
        }
        T *temp = a;
        a = b;
        b = temp;
    }

    if (a != arr)
    {
        for (int i = 0; i < len; i++){
            b[i] = a[i];
            std::cout<< b[i] << " ";
        }
        b = a;
    }       
    std::cout << std::endl;

    delete[] b;
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    mergeSortFunc(data);
    std::cout << std::endl;
    
    int data2[] = {13, 23, 2, 4, 8, 62, 19, 1};
    const int len = ARR_LENGTH(data2);
    mergeSort<int, len> ms(data2);
    ms.sort(0, len);
    
    return 0;
}
