// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-09

#include "ADT.h"

// 归并操作
// 归并两个有序的数列
int* Merging(int* arr1, int arr1_len, int* arr2, int arr2_len) {
    int i = 0, j = 0, k = 0;
    int* arr3 = new int[arr1_len + arr2_len];
    while(i < arr1_len && j < arr2_len) {
        while(arr1[i] <= arr2[j] && i < arr1_len) 
            arr3[k++] = arr1[i++];
        while(arr2[j] <= arr1[i] && j < arr2_len) 
            arr3[k++] = arr2[j++];
    }
    while(i < arr1_len) {
        arr3[k++] = arr1[i];
        i++;
    }
    while(j < arr2_len) {
        arr3[k++] = arr2[j];
        j++;
    }
    return arr3;
}

// 归并3个有序的数列
int* Merge3Sorted(int* arr1, int arr1_len, int* arr2, int arr2_len, int* arr3, int arr3_len) {
    int* ret = (int*)malloc(sizeof(int)* (arr1_len+arr2_len+arr3_len));
    ret = Merging(Merging(arr1, arr1_len, arr2, arr2_len), arr1_len+arr2_len, arr3, arr3_len);
    return ret;
}

//               (high)
//                 ↓
// arr: 2 5 8 12 | 5 6 7 10
//      ↑      ↑          ↑
//    beg_idx split_idx  end_idx
//     (low)        
// split_idx的选取是第一个sorted part的最后一个元素
void SortByMergeTwoSortedParts(int* arr, int beg_idx, int split_idx, int end_idx) {
    int low = beg_idx, high = split_idx + 1, k = 0;         // low:  数组1起始索引   high：数组2起始索引   k=0
    int len = end_idx - beg_idx + 1;                        // 区间长度
    int* arr_sorted = new int[len];                         // 开辟新数组存放排序完成的结果
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

// low:  low_index
// high: high_index
// 
void MergeSort(int* arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2; 
        MergeSort(arr, low, mid);               // 左半区间
        MergeSort(arr, mid+1, high);            // 右半区间
        SortByMergeTwoSortedParts(arr, low, mid, high);
    }
}

int main() {
    // bubble sort test
    // test case
    // int arr[] = {5, 2, 8, 3, 1, 7};         // 普通乱序
    // int arr[] = {1, 2, 3, 4, 5, 6};         // 已有序
    // int arr[] = {6, 5, 4, 3, 2, 1};         // 逆序
    // int arr[] = {3, 3, 2, 1, 2, 3};         // 有重复元素
    // int arr[] = {42};                       // 单元素
    // int arr[] = {};                         // 空数组
    // int len = sizeof(arr) / sizeof(*arr);
    // Cmp_Sort<int>::BubbleSort(arr, len);
    // Cmp_Sort<int>::PrintArray(arr, len);

    // bubble sort test
    // test case
    // int arr[] = {5, 2, 8, 3, 1, 7};         // 普通乱序
    // int arr[] = {1, 2, 3, 4, 5, 6};         // 已有序
    // int arr[] = {6, 5, 4, 3, 2, 1};         // 逆序
    // int arr[] = {3, 3, 2, 1, 2, 3};         // 有重复元素
    // int arr[] = {42};                       // 单元素
    // // int arr[] = {};                         // 空数组
    // int len = sizeof(arr) / sizeof(*arr);
    // Cmp_Sort<int>::InsertionSort(arr, len);
    // Cmp_Sort<int>::PrintArray(arr, len);

    // Selection Sort test
    // int arr[] = {5, 2, 8, 3, 1, 7};         // 普通乱序
    // int len = sizeof(arr) / sizeof(*arr);
    // Cmp_Sort<int>::SelectionSort(arr, len);
    // Cmp_Sort<int>::PrintArray(arr, len);

    // QuickSort Test
    // int arr[] = {5, 2, 8, 3, 1, 7};            // 普通乱序
    // int arr[] = {1, 2, 3, 4, 5, 6};         // 已有序
    // int arr[] = {3, 3, 2, 1, 2, 3};         // 有重复元素
    // int len = sizeof(arr) / sizeof(*arr);
    // Cmp_Sort<int>::PrintArray(arr, len);
    // Cmp_Sort<int>::QuickSort(arr, len);
    // Cmp_Sort<int>::PrintArray(arr, len);

    // Merging 2 Sorted list operation
    // int arr1[] = {1, 3, 5, 7, 9};               // 长度为5，升序
    // int arr2[] = {2, 4, 6, 8, 9, 10, 12};       // 长度为7，升序
    // int arr1_len = sizeof(arr1) / sizeof(*arr1), arr2_len = sizeof(arr2) / sizeof(*arr2);
    // int* arr3 = Merging(arr1, arr1_len, arr2, arr2_len);
    // int arr3_len = arr1_len + arr2_len;
    // for(int i = 0; i < arr3_len; i++) 
    //     cout << arr3[i] << ' ';

    // Merging 3 Sorted list
    // int arr1[] = {1, 4, 9};                // 长度3
    // int arr2[] = {2, 5, 8, 11};            // 长度4
    // int arr3[] = {0, 3, 6, 7, 10, 12};      // 长度6 
    // int arr1_len = sizeof(arr1) / sizeof(*arr1);
    // int arr2_len = sizeof(arr2) / sizeof(*arr2);
    // int arr3_len = sizeof(arr3) / sizeof(*arr3);
    // int* merged = Merge3Sorted(arr1, arr1_len, arr2, arr2_len, arr3, arr3_len);
    // int merged_len = arr1_len + arr2_len + arr3_len;
    // for(int i = 0; i < merged_len; i++)
    //     cout << merged[i] << ' ';

    // Sort a list that can be split into 2 sorted list using Merge
    // Output: 2 5 6 7 8 10 12 13
    // int arr[] = {2,5,8,12,5,6,7,10};                        // 2 5 8 12 13 | 6 7 10
    // int arrlen = sizeof(arr) / sizeof(*arr);                
    // SortByMergeTwoSortedParts(arr, 0, 3, arrlen - 1);
    // for(int i = 0; i < arrlen; i++) 
    //     cout << arr[i] << ' ';

    // Merge Sort Test  归并排序
    // int arr[] = {5, 2, 8, 3, 1, 7};         // 普通乱序
    // int arr[] = {3, 3, 2, 1, 2, 3};            // 有重复元素
    // // int arr[] = {1, 2, 3, 4, 5, 6};         // 已有序
    // int arrlen = sizeof(arr) / sizeof(*arr);
    // Cmp_Sort<int>::MergeSort(arr, 0, arrlen-1);
    // for(int i = 0; i < arrlen; i++) 
    //     cout << arr[i] << ' ';

    // Counting Sort 计数排序
    // int arr[] = {4, 2, 2, 8, 3, 3, 1};               // 有重复元素，范围小
    // int arr[] = {0, 1, 2, 3, 4, 5};                  // 已有序
    // int arr[] = {5, 4, 3, 2, 1, 0};                  // 逆序
    // int arr[] = {7, 7, 7, 7, 7};  
    // int arr[] = {-3, -1, -2, 0, 2, 1, -1, 2, 0, -3};    // 有负数
    // int len = sizeof(arr) / sizeof(*arr);
    // Idx_Sort<int>::CountingSort(arr, len);
    // for(int i = 0; i < len; i++)
    //     cout << arr[i] << ' ';

    // Bucket Sort 桶排序
    // int arr[] = {5, 4, 3, 2, 1, 0};                  // 逆序
    // int arr[] = {4, 2, 2, 8, 3, 3, 1};               // 有重复元素，范围小
    // int arr[] = {5, 2, 8, 3, 1, 7};
    // int arr[] = {-3, -1, -2, 0, 2, 1, -1, 2, 0, -3};
    // // double arr[] = {0.1, 0.5, 0.3, 0.9, 0.2};

    // int len = sizeof(arr) / sizeof(*arr);
    // Idx_Sort<int>::BucketSort(arr, len);
    // for(int i = 0; i < len; i++)
    //     cout << arr[i] << ' ';

    // Radix Sort 基数排序
    // int arr[] = {51, 4, 3, 2, 1, 100};
    // int arr[] = {-5, -10, 0, -3, 8, 5, -1, 10};
    // int arr[] = {7, 7, 7, 7, 7};
    // int arr[] = {6};
    // int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int len = sizeof(arr) / sizeof(*arr);
    // Idx_Sort<int>::RadixSort(arr, len);
    // for(int i = 0; i < len; i++)
    //     cout << arr[i] << ' ';

    // Shell Sort 希尔排序
    int arr[] = {5, 2, 8, 3, 1, 7};
    int len = sizeof(arr) / sizeof(*arr);
    Cmp_Sort<int>::ShellSort(arr, len);
    for(int i = 0; i < len; i++)
        cout << arr[i] << ' ';
}