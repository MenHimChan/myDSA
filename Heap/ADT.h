// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-07
#ifndef _ADT_H_
#define _ADT_H_

#include <iostream>
#define MAX_HEAP_SIZE 1000
using namespace std;

int arr_rchild_idx(int i, int arr_size);
int arr_lchild_idx(int i, int arr_size);
int arr_parent_idx(int i, int arr_size);

template <class T>
class MaxHeap {
private:
    T data[MAX_HEAP_SIZE];
    int size;
    int parent_idx(int i);          // 求索引为i的节点的父节点的索引
    int lchild_idx(int i);
    int rchild_idx(int i);
    static void swap(T* a, T* b);
    static void Heapify(T* arr, int arrlen, int i);

public:
    MaxHeap() : size(0) {}
    // ~MaxHeap();                  // data, size都不是用动态分配的内存，不需要手动释放。
    void Insert(T key);
    void Create();
    void Display();
    void InsertArray(T* array, int arr_len);
    T pop();
    int GetSize() {return this->size;}
    static void HeapSort(T* arr, int arrlen);
    static void HeapifyArray(T* arr, int arrlen);       // 将arr数组堆化
};

// cin >> overload for MaxHeap Class
template <class T>
std::istream& operator>>(std::istream& in, MaxHeap<T>& heap);

template <class T>
void MaxHeap<T>::HeapifyArray(T* arr, int arrlen) {
    int start = arrlen / 2 - 1;
    for(int i = start; i >= 0; i--) 
        Heapify(arr, arrlen, i);
}

// heapify an array
template <class T>
void MaxHeap<T>::Heapify(T* arr, int arrlen, int i) {
    int curr_idx = i;
    int lc_idx = arr_lchild_idx(curr_idx, arrlen);
    int rc_idx = arr_rchild_idx(curr_idx, arrlen);

    // has both left and right child
    if(lc_idx != -1 && rc_idx != -1) {
        // curr >= lchild and rchild
        if(arr[curr_idx] >= arr[rc_idx] && arr[curr_idx] >= arr[lc_idx]) return;
        // curr < lchild or curr < rchild
        // pick the larger child to swap with curr
        else if(arr[curr_idx] < arr[rc_idx] || arr[curr_idx] < arr[lc_idx]) {
            if(arr[rc_idx] < arr[lc_idx]) {
                swap(&arr[curr_idx], &arr[lc_idx]);
                Heapify(arr, arrlen, lc_idx);
            }
            else {
                swap(&arr[curr_idx], &arr[rc_idx]);
                Heapify(arr, arrlen, rc_idx);
            }
        }
    }
    // has only 1 child, it must be lchild
    else if(lc_idx != -1 && rc_idx == -1) {
        if(arr[lc_idx] <= arr[curr_idx]) return;
        else {
            swap(&arr[lc_idx], &arr[curr_idx]);
            Heapify(arr, arrlen, lc_idx);
        }
    }
    // has no child, leaf node, return
    else
        return;
}


template <class T>
void MaxHeap<T>::HeapSort(T* arr, int arrlen) {
    MaxHeap<T> maxheap;
    maxheap.InsertArray(arr, arrlen);
    for(int i = 0; i < arrlen; i++) 
        arr[i] = maxheap.pop();
}

template <class T>
T MaxHeap<T>::pop() {
    if(size == 0)           // 如果堆已经空了，则直接返回-1
        return -1;
    else {
        T retval = data[0];             // 保存堆顶元素便于返回
        int curr_idx;            
        data[0] = data[size - 1];       // 用最后一个元素覆盖堆顶元素, 成为根节点
        curr_idx = 0;                   
        size--;
        while(true) {
            int lc_idx = lchild_idx(curr_idx);
            int rc_idx = rchild_idx(curr_idx);
            // lchild exists && rchild exists
            if(lc_idx != -1 && rc_idx != -1) {
                if(data[curr_idx] >= data[rc_idx] && data[curr_idx] >= data[lc_idx])
                    break;
                // pick the larest elements and swap 
                if(data[curr_idx] < data[rc_idx] || data[curr_idx] < data[lc_idx]) {
                    if(data[rc_idx] > data[lc_idx]) {
                        swap(&data[rc_idx], &data[curr_idx]);
                        curr_idx = rchild_idx(curr_idx);
                    }
                    else {
                        swap(&data[lc_idx], &data[curr_idx]);
                        curr_idx = lchild_idx(curr_idx);
                    }
                }
            }
            // only exists rchild
            else if(lc_idx == -1 && rc_idx != -1) {
                if(data[curr_idx] >= data[rc_idx])
                    break;
                else {
                    swap(&data[rc_idx], &data[curr_idx]);
                    curr_idx = rchild_idx(curr_idx);
                }
            }
            // only exists lchild
            else if(lc_idx != -1 && rc_idx == -1) {
                if(data[curr_idx] >= data[lc_idx])
                    break;
                else {
                    swap(&data[lc_idx], &data[curr_idx]);
                    curr_idx = lchild_idx(curr_idx);
                }
            }
            // has not child node
            else 
                break;
        }
        return retval;
    }
}

template <class T>
int MaxHeap<T>::rchild_idx(int i) {
    int idx = 2*i + 2;
    if(i < 0 || i >= size || idx >= size)
        return -1;
    return idx;
}

template <class T>
int MaxHeap<T>::lchild_idx(int i) {
    int idx = 2*i + 1;
    if(i >= size || i < 0 || idx >= size)  // 输入越界，或者是计算出的lchild索引越界均不合法
        return -1;
    return idx;
}

template <class T>
void MaxHeap<T>::Display() {
    for(int i = 0; i < size; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

template <class T>
std::istream& operator>>(std::istream& in, MaxHeap<T>& heap) {
    T x;
    in >> x;
    while(x != -1) {
        heap.Insert(x);
        in >> x;
    }
    return in;
}

template <class T>
void MaxHeap<T>::swap(T* a, T* b) {
    T tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// 越界返回-1
template <class T>
int MaxHeap<T>::parent_idx(int i) {
    if(i <= 0 || i >= size)             // 根节点不能有parent，不合法的节点索引不能有parent
        return -1;
    return (i - 1) / 2;
}

template <class T>
void MaxHeap<T>::Insert(T newelem) {
    int newelem_idx = size;             // 新节点接在最后
    data[size] = newelem;
    size++;
    while(newelem_idx > 0 && data[parent_idx(newelem_idx)] < data[newelem_idx]) {
        swap(&data[parent_idx(newelem_idx)], &data[newelem_idx]);
        newelem_idx = parent_idx(newelem_idx);
    }
}

template <class T>
void MaxHeap<T>::InsertArray(T* array, int arr_len) {
    for(int i = 0; i < arr_len; i++) 
        Insert(array[i]);
}

template <class T>
void MaxHeap<T>::Create() {
    T x;
    cin >> x;
    while(x != -1) {
        Insert(x);
        cin >> x;
    }
}

#endif