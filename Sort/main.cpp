// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-09

#include "ADT.h"

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
    int arr[] = {3, 3, 2, 1, 2, 3};         // 有重复元素
    int len = sizeof(arr) / sizeof(*arr);
    Cmp_Sort<int>::PrintArray(arr, len);
    Cmp_Sort<int>::QuickSort(arr, len);
    Cmp_Sort<int>::PrintArray(arr, len);

}