// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-09

#ifndef __ADT__H__
#define __ADT__H__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>
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
    static void ShellSort(T* arr, int len);
};

template <class T>
void Cmp_Sort<T>::ShellSort(T* arr, int len) {
    for(int gap = len/2; gap != 1; gap /= 2) {
        int i = 0;                                  // start idx
        do {
            vector<T> vec;
            // 将分组内的所有元素装入vector等待排序
            for(int j = i; j < len; j+=gap) vec.push_back(arr[j]);

            // 本组只有一个元素，不需要排序，说明所有分组已处理完，结束本轮gap的分组循环
            if(vec.size() == 1) break;        
            
            sort(vec.begin(), vec.end());
            auto it = vec.begin();
            for(int j = i; j < len; j+=gap) arr[j] = *(it++);
        }while(i++);
    }
    // 最后一轮gap = 1，直接调用插入排序
    InsertionSort(arr, len);
}

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
        T toInsert = arr[i];             // 无序区第一个元素，待插入的元素
        int j = i - 1;              // 有序区最后一个元素（最大元素）索引
        while(j >= 0 && arr[j] > toInsert) {
            arr[j+1] = arr[j];      // rightshirft
            j--;
        }
        arr[j+1] = toInsert;
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

template <class T>
class Idx_Sort {
private:
    struct Node{
        T data;
        Node* next;
    };
    static T GetMaxVal(T* arr, int len);
    static T GetMinVal(T* arr, int len);
public:
    static void CountingSort(T* arr, int len);
    static void CountingSort_LinkedList(T* arr, int len);
    static void BucketSort(T* arr, int len);
    static void RadixSort(T* arr, int len); 
};

template <class T>
void Idx_Sort<T>::RadixSort(T* arr, int len) {
    T mn = GetMinVal(arr, len), mx= GetMaxVal(arr, len);
    vector<queue<T>> vec(10);                   // 十个基数，0~9
    int round = 0;
    bool hasnagative = false;
    if(mn < 0) {
        for(int i = 0; i < len; i++) 
            arr[i] += mn*(-1);
        hasnagative = true;
    }
    while(mx != 0) {
        mx /= 10;
        round++;
    }
    for(int i = 0, exp = 1; i < round; i++, exp*=10) {
        // 遍历数组，数组元素 -> vector
        for(int j = 0; j < len; j++) {
            T radix = (arr[j] / exp) % 10;
            vec[radix].push(arr[j]);
        }
        // 遍历vector，vector 写回数组
        for(int j = 0, k = 0; j < 10; j++) {
            while(!vec[j].empty()) {
                arr[k++] = vec[j].front();
                vec[j].pop();
            }
        }
    }
    if(hasnagative)
        for(int i = 0; i < len; i++) arr[i] += mn;
}

template <class T>
void Idx_Sort<T>::BucketSort(T* arr, int len) {
    T minval = GetMinVal(arr, len), maxval = GetMaxVal(arr, len);
    T interval_len = maxval - minval;
    int bucket_num = len;                                           // 桶数等于数组长度，平均每个桶装一个数
    vector<vector<T>> buckets(bucket_num);

    // 数组元素入桶
    for(int i = 0; i < len; i++) {
        int bucket_idx = (arr[i] - minval) * 1.0 / (interval_len + 1) * bucket_num;
        // cout << "i: " << i << " arr[i]: " << arr[i] << " bucket_idx : " << bucket_idx << endl;
        buckets[bucket_idx].push_back(arr[i]);
    }

    // 对每个桶中的元素排序
    for(int i = 0; i < bucket_num; i++) 
        sort(buckets[i].begin(), buckets[i].end());

    // 写回原数组
    int k = 0;
    for(int i = 0; i < bucket_num; i++) 
        for(auto it = buckets[i].begin(); it != buckets[i].end(); it++)
            arr[k++] = *it;
}

template <class T>
void Idx_Sort<T>::CountingSort_LinkedList(T* arr, int len) {
    T maxval = GetMaxVal(arr, len);
    int k = 0;
    vector<Node*> vec(maxval+1, nullptr);
    for(int i = 0; i < len; i++) {
        // 首次插入
        if(vec[arr[i]] == nullptr) {
            vec[arr[i]] = new Node{arr[i], nullptr};
        }
        else {
            Node* newnode = new Node{arr[i], nullptr};
            Node* p = vec[arr[i]];
            while(p->next != nullptr) p = p->next;
            p->next = newnode;
        }
    }
    for(auto it = vec.begin(); it != vec.end(); it++) {
        Node* p = *it;
        while(p != nullptr) {
            arr[k++] = p->data;
            p = p->next;
        }
    }
    // delete Node
    for(auto it = vec.begin(); it != vec.end(); it++) {
        Node* p = *it;
        while(p != nullptr) {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
    }
}

template <class T>
T Idx_Sort<T>::GetMinVal(T* arr, int len) {
    T minval = arr[0];
    for(int i = 0; i < len; i++) 
        if(minval > arr[i])
            minval = arr[i];
    return minval;
}

template <class T>
T Idx_Sort<T>::GetMaxVal(T* arr, int len) {
    T maxval = arr[0];
    for(int i = 0; i < len; i++) 
        if(maxval < arr[i])
            maxval = arr[i];
    return maxval;
}

template <class T>
void Idx_Sort<T>::CountingSort(T* arr, int len) {
    T minval = GetMinVal(arr, len);
    bool hasNegatvive = false;
    if(minval < 0) {
        for(int i = 0; i < len; i++)
            arr[i] += minval*(-1);
        hasNegatvive = true;
    }
    T maxval = GetMaxVal(arr, len);
    T aid[maxval + 1] = {};
    int k = 0;
    for(int i = 0; i < len; i++)        // 统计原始数组中每个元素出现的次数
        aid[arr[i]]++;
    for(int i = 0; i <= maxval; i++) {  // 遍历aid数组，对arr进行重新排序
        while(aid[i] != 0) {
            arr[k++] = i;
            aid[i]--;
        }
    }
    if(hasNegatvive)
        for(int i = 0; i < len; i++)
            arr[i] += minval;
}



#endif