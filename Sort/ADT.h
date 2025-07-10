// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-09

#ifndef __ADT__H__
#define __ADT__H__

#include <iostream>
using namespace std;

template <class T>
class Cmp_Sort {
private:
    static void swap(T* a, T* b);
public:
    static void PrintArray(T* arr, int len);
    static void BubbleSort(T* arr, int len);
    static void InsertionSort(T* arr, int len);
    static void SelectionSort(T* arr, int len);
};

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