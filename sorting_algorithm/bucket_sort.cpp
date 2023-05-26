#include <iostream>
#include <vector>
const int BUCKET_NUM = 10;
#define ARR_LENGTH(arr)    sizeof(arr)/sizeof(arr[0])


struct ListNode
{
    explicit ListNode(int i=0):mData(i), mNext(nullptr){}
    ListNode* mNext;
    int mData;
};

ListNode* insert(ListNode* head, int val){
    ListNode dummyNode;
    ListNode *newNode = new ListNode(val);
    ListNode *pre, *curr;
    dummyNode.mNext = head;
    pre = &dummyNode;
    curr = head;
    while(curr != nullptr && curr->mData <= val){
        pre = curr;
        curr = curr->mNext;
    }
    newNode->mNext = curr;
    pre->mNext = newNode;
    return dummyNode.mNext;
}

ListNode* merge(ListNode* head1, ListNode* head2){
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->mData <= head2->mData){
            dummy->mNext = head1;
            head1 = head1->mNext;
        }else{
            dummy->mNext = head2;
            head2 = head2->mNext;
        }
        dummy = dummy->mNext;
    }
    if(head1 != nullptr) dummy->mNext = head1;
    if(head2 != nullptr) dummy->mNext = head2;
    return dummyNode.mNext;
}


template <typename T, int len>
void printArr(T (&arr)[len]){
    for(int i = 0; i < len; i++)
        std::cout<< arr[i] << " ";
    std::cout << std::endl;
}



template <typename T, int len>
void bucketSortFunc(T (&arr)[len])
{
    std::cout << "=== bucket sort function ===" << std::endl;
    std::cout << "array len: " << len << std::endl;
    printArr(arr);

    std::vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
    for (int i = 0; i < len; ++i)     //把数组中的元素均匀分配到桶中并排序
    {
        int index = arr[i] / BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insert(head, arr[i]);
    }
    ListNode *head = buckets.at(0);
    for(int i=1; i < BUCKET_NUM; ++i){
        head = merge(head, buckets.at(i));  //将排序好的桶中元素合并
    }
    for(int i=0; i < len; ++i){
        arr[i] = head->mData;
        head = head->mNext;
    }

    printArr(arr);
}



int main() {

    int data[] = {13, 23, 2, 4, 8, 54, 19, 1};
    bucketSortFunc(data);
    
    return 0;
}
