// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-09

#ifndef __ADT__H__
#define __ADT__H__

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class Cmp_Sort {
private:
    static void swap(T* a, T* b);
    static void SortByMergeTwoSortedParts(T* arr, int beg_idx, int split_idx, int end_idx);
public:
    static void PrintArray(T* arr, int len);
    static void BubbleSort(T* arr, int len);
    static void InsertionSort(T* arr, int len);
    static void SelectionSort(T* arr, int len);
    static void QuickSort(T* arr, int len);
    static void MergeSort(T* arr, int low, int high);
};

template <class T>
void Cmp_Sort<T>::MergeSort(T* arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        SortByMergeTwoSortedParts(arr, low, mid, high);
    }
}

template <class T>
void Cmp_Sort<T>::SortByMergeTwoSortedParts(T* arr, int beg_idx, int split_idx, int end_idx) {
    int low = beg_idx, high = split_idx + 1, k = 0;         // low:  数组1起始索引   high：数组2起始索引   k=0
    int len = end_idx - beg_idx + 1;                        // 区间长度
    T* arr_sorted = new int[len];                         // 开辟新数组存放排序完成的结果
    while(low <= split_idx && high <= end_idx) {
        while(low <= split_idx && arr[low] <= arr[high])
            arr_sorted[k++] = arr[low++];
        while(high <= end_idx && arr[high] <= arr[low])
            arr_sorted[k++] = arr[high++];
    }
    while(low <= split_idx)
        arr_sorted[k++] = arr[low++];
    while(high <= end_idx)
        arr_sorted[k++] = arr[high++];
    for(int i = 0; i < len; i++) arr[i + beg_idx] = arr_sorted[i];
    delete[] arr_sorted;
}

// arr数组中任何一个值作为pivot都不影响结果的正确性
// 所以pivot最好是随机取，否则万一输入的数列本身就是有序的造成退化
template <class T>
void Cmp_Sort<T>::QuickSort(T* arr, int len) {
    if(len <= 1) return;
    int pivot_idx = rand() % len;   // 取0~len - 1为索引的任意一个值作为pivot
    T pivot = arr[pivot_idx];
    int left = 0, right = len-1, vac = pivot_idx;
    while(left != right) {
        while(left != right) {
            if(arr[right] < pivot) {
                arr[vac] = arr[right];
                vac = right;
                break;
            }
            else
                right--;
        }
        while(left != right) {
            if(arr[left] > pivot) {
                arr[vac] = arr[left];
                vac = left;
                break;
            } 
            else 
                left++;
        }
    }
    arr[vac] = pivot;
    QuickSort(arr, vac);                         // left interval, idx from (0 ~ vac - 1)
    QuickSort(arr + vac + 1, len - vac - 1);     // right interval, idx from (vac + 1 ~ len - 1)
}

template <class T>
void Cmp_Sort<T>::SelectionSort(T* arr, int len) {
    for(int processing_idx = 0; processing_idx <= len - 2; processing_idx++) {
        int min_idx = processing_idx;
        for(int i = min_idx + 1; i < len; i++) 
            if(arr[i] < arr[min_idx])
                min_idx = i;
        swap(&arr[processing_idx], &arr[min_idx]);
    }
}

template <class T>
void Cmp_Sort<T>::InsertionSort(T* arr, int len) {
    for(int i = 1; i < len; i++) {
        T tmp = arr[i];             // 无序区第一个元素，待插入的元素
        int j = i - 1;              // 有序区最后一个元素（最大元素）索引
        while(j >= 0 && arr[j] > tmp) {
            arr[j+1] = arr[j];      // rightshirft
            j--;
        }
        arr[j+1] = tmp;
    }
}

template <class T>
void Cmp_Sort<T>::PrintArray(T* arr, int len) {
    for(int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template <class T>
void Cmp_Sort<T>::swap(T* a, T* b) {
    T tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class T>
void Cmp_Sort<T>::BubbleSort(T* arr, int len) {
    bool noswap;
    for(int i = 1; i < len; i++) {
        noswap = true;
        for(int j = 0; j <= len-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                noswap = false;
            }
        }
        if(noswap)  
            return;
    }
}




















#endif