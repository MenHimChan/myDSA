// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-06

#include "ADT.h"
#include <iostream>
using namespace std;

int main() {
    // basic test
    // test case: 8 6 7 1 4 3 6,  Insert 9
    // MaxHeap<int> maxheap;
    // maxheap.Create();
    // maxheap.Display();
    // maxheap.Insert(9);
    // maxheap.Display();

    // cin >> heap test
    // MaxHeap<int> maxheap;
    // cin >> maxheap;
    // maxheap.Display();
    // maxheap.Insert(9);
    // maxheap.Display();
    
    // single elements
    // MaxHeap<int> maxheap;
    // maxheap.Insert(1);
    // maxheap.Display();
    // maxheap.Insert(100);
    // maxheap.Display();
    
    // put an array into heap
    // MaxHeap<int> maxheap;
    // maxheap.Create();
    // maxheap.Display();
    // int arr[] = {123,314,1987,123,58,89};
    // maxheap.InsertArray(arr, 6);
    // maxheap.Display();

    // pop() test
    // int arr[10] = {23, 5, 87, 12, 45, 3, 99, 56, 31, 77};
    // MaxHeap<int> maxheap;
    // maxheap.InsertArray(arr, 10);
    // maxheap.Display();
    // for(int i = 0; i < 10; i++)
    //     cout << maxheap.pop() << ' ';

    // HeapSort() test
    // test case: 42, 17, 8, 99, 23, 56, 1, 73, 65, 12, 38
    //            23, 5, 87, 12, 45, 3, 99, 56, 31, 77
    // int arr[] = {23, 5, 87, 12, 45, 3, 99, 56, 31, 77};
    // int len = 10;
    // MaxHeap<int>::HeapSort(arr, len);
    // for(int i = 0; i < len; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    // return 0;

    // Heapify() an array
    // test case: 42, 17, 8, 99, 23, 56, 1, 73, 65, 12, 38
    //            23, 5, 87, 12, 45, 3, 99, 56, 31, 77
    // int arr[] = {23, 5, 87, 12, 45, 3, 99, 56, 31, 77};
    // int len = sizeof(arr) / sizeof(arr[0]);
    // MaxHeap<int>::HeapifyArray(arr, len);
    // for(int i = 0; i < len; i++)  cout << *(arr + i) << ' ';
    // cout << endl;

    // MaxHeap as larger priority_queue
    // 不断将元素入堆，然后逐个pop出来就是最大优先队列
    int arr[] = {23, 5, 87, 12, 45, 3, 99, 56, 31, 77};
    int len = sizeof(arr) / sizeof(arr[0]);
    MaxHeap<int> max_priority_queue;
    max_priority_queue.InsertArray(arr, len);
    for(int i=0; i<len; i++) 
        cout << max_priority_queue.pop() << ' ';
}