// ADT.h
#ifndef ADT_H  // 防止头文件重复包含
#define ADT_H
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

// 动态数组结构体
struct Array
{
    int* ptr;
    int size;     // 数组的总容量
    int length;   // 数组当前已使用的长度
};

// 固定数组结构体
struct Array_fixed
{
    int A[20];
    int size;
    int length;
};

// 辅助函数
void swap(int* a, int* b);

// 函数声明
void Display(struct Array arr);
void Append(struct Array* arr, int x);
void Insert(struct Array* arr, int index, int x);
int Delete(struct Array* arr, int index);
int LinearSearch(struct Array* arr, int key);
int LinearSearch_imporved(struct Array* arr, int key);
int BinarySearch(struct Array* arr, int key);
int RBinarySearch(struct Array* arr, int low, int high, int key);
int Get(struct Array* arr, int index);
void Set(struct Array* arr, int index, int value);
int Max(struct Array* arr);
int Min(struct Array* arr);
int Sum(struct Array* arr);
float Avg(struct Array* arr);
void Reverse_cpy(struct Array* arr);
void Reverse_swap(struct Array* arr);
void lshirft(struct Array* arr);
void lrotat(struct Array* arr);
void Insert_sorted(struct Array* arr, int value);
bool isSorted(struct Array* arr);
void Rearrange(struct Array* arr);
struct Array Merge(struct Array* arr1, struct Array* arr2);
struct Array Union(struct Array* arr1, struct Array* arr2);
struct Array Union_sorted(struct Array* arr1, struct Array* arr2);
struct Array Intersection(struct Array* arr1, struct Array* arr2);
struct Array Difference(struct Array* arr1, struct Array* arr2);

template <class T>
class ArrayClass
{
private:
    T* ptr;
    int size;
    int length;
    void swap(T* a, T* b);

public:
    ArrayClass();                                   // default constructor
    ArrayClass(int sz);                             // parameters constructor
    ~ArrayClass();                                  // deconstructor
    ArrayClass(const ArrayClass& other);            // Copy constructor
    int GetSize(void){return size;}
    int GetLength(void){return length;}
    void Display(void);                                 
    void SetArray(int len);                         // use the cin function to set the array, fill len of elements into the array
    void SetLength(int newlength);                  // set the length of the array to new length
    void Append(T x);                               // Append an elements to the end of the array
    void Insert(int index, T x);                    // Insert x into an array
    int Delete(int index);                          // Delete element acccording to index
    int LinearSearch(T key);                        // Linear search
    int BinarySearch(T key);                        // Binary Search
    T Get(int index);                               // Get the index elements
    void Set(int index, T value);                   // Set the index elements to value
    T Max(void);                                    // return the max elements of the array
    T Min(void);                                    // return the min elements of the array
    T Sum(void);                                    // return the sum of the array
    float Avg(void);                                // return the average value of the array
    void Reverse_swap(void);                        // Reverse the whole array using swap function
    void lshirft(void);                             // Left shirft the array, last elements fill with 0
    void lrotat(void);                              // Left rotate the array
    void Insert_sorted(T value);                    // Insert the value into a sorted array
    bool isSorted(void);
    void Rearrange(void);
    static ArrayClass<T> Merge(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2);
    static ArrayClass<T> Union(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2);
    static ArrayClass<T> Intersection(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2);
    static ArrayClass<T> Difference(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2);

};

/*************************** class member function implementation ******************************/
// default constructor 
template <class T>
ArrayClass<T>::ArrayClass()
{
    size = 10;
    length = 0;
    ptr = (T*)malloc(sizeof(T) * size);
}

// parameter constructor
template <class T>
ArrayClass<T>::ArrayClass(int sz)
{
    size = sz;
    length = 0;
    ptr = (T*)malloc(sizeof(T) * size);
}

// deconstructor
template <class T>
ArrayClass<T>::~ArrayClass(void)
{
    delete []ptr;
}

template <class T>
ArrayClass<T>::ArrayClass(const ArrayClass& other)
{
    // 在构造函数体内初始化成员
    size = other.size;
    length = other.length;
    ptr = new T[other.size];
    
    // 复制元素
    for(int i = 0; i < other.length; i++) 
        ptr[i] = other.ptr[i];
}


template <class T>
void ArrayClass<T>::swap(T* a, T* b)
{
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
void ArrayClass<T>::Display(void)
{
    cout << "Elements of the array is: \n";
    for(int i = 0; i < length; i++)
        cout << ptr[i] << ' ';
    cout << endl;
}

template <class T>
void ArrayClass<T>::SetArray(int len)
{
    cout << "Input the array you want: \n";
    if(len <= size)
    {
        for(int i = 0; i < len; i++)
            cin >> ptr[i];
        length = len;
    }
}

template <class T>
void ArrayClass<T>::SetLength(int newlength)
{
    if(newlength <= size)
        length = newlength;
}

template <class T>
void ArrayClass<T>::Append(T x)
{
    if(length + 1 <= size)
    {
        ptr[length] = x;
        length++;
    }
}

template <class T>
void ArrayClass<T>::Insert(int index, T x)
{
    if(length + 1 < size)
    {
        if(index >= 0 && index < length)
        {
            for(int i = length - 1; i >= index; i--)
                ptr[i + 1] = ptr[i];
            ptr[index] = x;
            length++;
        }
    }
}

// return the value of the delete elements if succeed, else return -1
template <class T>
int ArrayClass<T>::Delete(int index)
{
    int retval;
    if(index >= 0 && index <= length - 1)
    {
        retval = ptr[index];
        for(int i = index; i < length - 1; i++)
            ptr[i] = ptr[i + 1];
        length--;
        return retval;
    }
    return -1;
}

template <class T>
int ArrayClass<T>::LinearSearch(T key)
{
    for(int i = 0; i < length; i++)
        if(key == ptr[i])
            return i;
    return -1;
}

template <class T>
int ArrayClass<T>::BinarySearch(T key)
{
    int low = 0, high = length - 1;
    int mid = (low + high) / 2;

    while(low <= high)           // 如果待查找元素在最后一个位置确保了判断条件是i<j
    {
        if(key == ptr[mid])
            return mid;
        else if(key > ptr[mid])
        {
            low= mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

template <class T>
T ArrayClass<T>::Get(int index)
{
    if(index >= 0 && index < length)
        return ptr[index];
    return -1;
}

template <class T>
void ArrayClass<T>::Set(int index, T value)
{
    if(index >= 0 && index < length)
        ptr[index] = value;
}

template <class T>
T ArrayClass<T>::Max(void)
{
    int max = ptr[0];
    for(int i = 0; i < length; i++)
    {
        if(ptr[i] > max)
            max = ptr[i];
    }
    return max;
}

template <class T>
T ArrayClass<T>::Min(void)
{
    int min = ptr[0];
    for(int i = 0; i < length; i++)
    {
        if(ptr[i] < min)
            min = ptr[i];
    }
    return min;   
}

template <class T>
T ArrayClass<T>::Sum(void)
{
    int sum = 0;
    for(int i = 0; i < length; i++)
        sum += ptr[i];
    return sum;
}

template <class T>
float ArrayClass<T>::Avg(void)
{
    return (float)Sum() / length;
}

template <class T>
void ArrayClass<T>::Reverse_swap(void)
{
    int i = 0, j = length - 1;
    while (i <= j)
    {
        swap(ptr + i, ptr + j);
        i++;
        j--;
    }
}

template <class T>
void ArrayClass<T>::lshirft(void)
{
    for(int i = 0; i < length - 1; i++)
        ptr[i] = ptr[i + 1];
    ptr[length - 1] = 0;
}

template <class T>
void ArrayClass<T>::lrotat(void)
{
    int tmp = ptr[0];
    lshirft();
    ptr[length - 1] = tmp;
}

template <class T>
void ArrayClass<T>::Insert_sorted(T value)
{
    int i = length - 1;
    while (value < ptr[i])
    {
        ptr[i + 1] = ptr[i];  // do the right shirft
        i--;
    }
    ptr[i + 1] = value;
    length ++;
}

template <class T>
bool ArrayClass<T>::isSorted(void)
{
    for(int i = 0; i < length - 1; i++)
    {
        if(ptr[i] > ptr[i + 1])
            return false;
    }
    return true;    
}

template <class T>
void ArrayClass<T>::Rearrange(void)
{
    int i = 0, j = length - 1;
    while(i <= j)
    {
        while(ptr[i] < 0)
            i++;
        while (ptr[j] >= 0)
            j--;
        if(i < j)
            swap(ptr + i, ptr + j);
    }
}

// Brief: Merge arr1 and arr2 and return the merge array3
// arr3 length = arr1 length + arr2 length
// arr3 size = arr1 size + arr2 size
// Note: the arr1 and arr2 must be sorted 
template <class T>
ArrayClass<T> ArrayClass<T>::Merge(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2)
{
    ArrayClass<T> arr3(arr1.size + arr2.size);
    int i = 0, j = 0;
    arr3.length = arr1.length + arr2.length;
    arr3.size = arr1.size + arr2.size;
    arr3.ptr = (T*)malloc(sizeof(T) * arr3.size);
    for(int k = 0; k < arr3.length - 1; k++)
    {
        if(arr1.ptr[i] <= arr2.ptr[j])
        {
            arr3.ptr[k] = arr1.ptr[i++];
            continue;
        }    
        if(arr2.ptr[j] <= arr1.ptr[i])
        {
            arr3.ptr[k] = arr2.ptr[j++];
            continue;
        }    
    }
    if (i < j)
        arr3.ptr[arr3.length - 1] = arr1.ptr[i];
    else    
        arr3.ptr[arr3.length - 1] = arr2.ptr[j];
        
    return arr3;
}

template <class T>
ArrayClass<T> ArrayClass<T>::Union(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2)
{
    ArrayClass<T> arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.ptr = new T[arr3.size];
    arr3.length = arr1.length;
    memcpy(arr3.ptr, arr1.ptr, sizeof(T)* arr1.length);
    for(int i = 0; i < arr2.length; i++)
    {
        bool append = true;
        for(int j = 0; j < arr1.length; j++)
        {
            if(arr2.ptr[i] == arr1.ptr[j])
            {
                append = false;
                break;
            }
        }
        if(append)
            arr3.Append(arr2.ptr[i]);
    }
    return arr3;
}

template <class T>
ArrayClass<T> ArrayClass<T>::Intersection(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2)
{
    ArrayClass<T> arr3;
    arr3.size = min(arr1.size, arr2.size);
    arr3.length = 0;
    arr3.ptr = new T[arr3.size];
    for(int i = 0; i < arr1.length; i++)
        for(int j = 0; j < arr2.length; j++)
            if(arr1.ptr[i] == arr2.ptr[j])
            {
                arr3.Append(arr1.ptr[i]);
                break;
            }
    return arr3;
}

template <class T>
ArrayClass<T> ArrayClass<T>::Difference(const ArrayClass<T>& arr1, const ArrayClass<T>& arr2)
{
    ArrayClass arr3;
    arr3.size = arr1.size;
    arr3.length = 0;
    arr3.ptr = new T[arr3.size];
    for(int i = 0; i < arr1.length; i++)
    {
        bool append = true;
        for(int j = 0; j < arr2.length; j++)
        {
            if(arr1.ptr[i] == arr2.ptr[j])
            {
                append = false;
                break;
            }
        }
        if(append)
            arr3.Append(arr1.ptr[i]);
    }
    return arr3;
}


#endif // ADT_H