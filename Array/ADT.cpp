#include "ADT.h"
using namespace std;

// print the Array structure
void Display(struct Array arr)
{
    cout << endl;
    cout << "Elements of the array is: \n";
    for(int i = 0; i < arr.length; i++)
        cout << arr.ptr[i] << ' ';
    cout << endl;
}

// Append x into the arrays
void Append(struct Array* arr, int x)
{
    if(arr -> length < arr -> size)
    {
        arr -> ptr[arr->length] = x;
        arr -> length++;
    }
}

// Insert x to the index
void Insert(struct Array* arr, int index, int x)
{
    if(arr -> length < arr -> size)
    {
        if(index >= 0 && index < arr -> length)    // valid index
        {
            for(int i = arr -> length; i > index; i--)
                arr -> ptr[i] = arr -> ptr[i - 1];
            arr -> ptr[index] = x;
            arr -> length++;
        }
    }
}

// Delete index elements
// Success, return the delete value, else return 0.
int Delete(struct Array* arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr -> length)
    {
        x = arr -> ptr[index];
        for(int i = index; i < arr -> length - 1; i++)
            arr -> ptr[i] = arr -> ptr[i + 1]; 
        arr -> length--;
        return x;
    }
    return 0;
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Linear search
int LinearSearch(struct Array* arr, int key)
{
    for(int i = 0; i < arr -> length; i++)
    {
        if(key == arr -> ptr[i])
            return i;
    }
    return -1;
}

// Linear search improved
// search key in the arrays, return the index, move the key to the front of array
int LinearSearch_imporved(struct Array* arr, int key)
{
    for(int i = 0; i < arr -> length; i++)
    {
        if(key == *(arr -> ptr + i))
        {
            swap(arr -> ptr + i, arr -> ptr);       // swap the target to the beginning of the array
            return i;
        }
    }
    return -1;
}

// Binary Search
// The array to be searched must be sorted.
// search key in the arrays, return the index if succeed, if failed return -1.
int BinarySearch(struct Array* arr, int key)
{
    int low = 0;
    int high = arr -> length - 1;
    int mid = (low + high) / 2;

    while(low <= high)
    {
        if(arr -> ptr[mid] == key)
            return mid;
        else if(arr -> ptr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    return -1;       
}
    
// Recursion Binary Search
// search key in the arrays, return the index if succeed, if failed return -1.
int RBinarySearch(struct Array* arr, int low, int high, int key)
{
    int mid;
    if(low <= high)
    {
        mid = (low + high) / 2;
        if(arr -> ptr[mid] == key)
            return mid;
        else if(arr -> ptr[mid] < key)
            return RBinarySearch(arr, mid + 1, high, key);
        else
            return RBinarySearch(arr, low, mid - 1, key);
    }
    return -1;
}

int Get(struct Array* arr, int index)
{
    if(index >= 0 && index < arr -> length)
        return arr -> ptr[index];
    return -1;
}

void Set(struct Array* arr, int index, int value)
{
    if(index >= 0 && index < arr -> length)
        arr -> ptr[index] = value;
}

int Max(struct Array* arr)
{
    int max = arr -> ptr[0];
    for(int i = 0; i < arr -> length; i++)
    {
        if(arr -> ptr[i] > max)
            max = arr -> ptr[i];
    }
    return max;
}

int Min(struct Array* arr)
{
    int min = arr -> ptr[0];
    for(int i = 0; i < arr -> length; i++)
    {
        if(arr -> ptr[i] < min)
            min = arr -> ptr[i];
    }
    return min;   
}

int Sum(struct Array* arr)
{
    int sum = 0;
    for(int i = 0; i < arr -> length; i++)
        sum += arr -> ptr[i];
    return sum;
}

float Avg(struct Array* arr)
{
    return (float)Sum(arr) / arr -> length;
}

// Reverse function implemented by copy
void Reverse_cpy(struct Array* arr)
{
    int temp[arr -> length];
    // 拷贝一份原来的逆序数组
    for(int i = 0, j = arr -> length - 1; i < arr -> length; i++, j--)
        temp[j] = arr -> ptr[i]; 
    // 直接覆盖原来的数组
    memcpy(arr -> ptr, temp, arr -> length * sizeof(int));
}

// Reverse function implemented by swap
void Reverse_swap(struct Array* arr)
{
    int i = 0, j = arr -> length - 1;
    while (i <= j)
    {
        swap(arr -> ptr + i, arr -> ptr + j);
        i++;
        j--;
    }
}

// left shirft, last element fill 0
void lshirft(struct Array* arr)
{
    for(int i = 0; i < arr -> length - 1; i++)
        arr -> ptr[i] = arr -> ptr[i + 1];
    arr -> ptr[arr -> length - 1] = 0;
}

// left rotate
void lrotat(struct Array* arr)
{
    int tmp = arr -> ptr[0];
    lshirft(arr);
    arr -> ptr[arr -> length - 1] = tmp;
}


// Insert an elements into a sorted array
void Insert_sorted(struct Array* arr, int value)
{
    int i = arr -> length - 1;
    while (value < arr -> ptr[i])
    {
        arr -> ptr[i + 1] = arr -> ptr[i];  // do the right shirft
        i--;
    }
    arr -> ptr[i + 1] = value;
    arr -> length ++;
}

// Check the array is sorted or not
bool isSorted(struct Array* arr)
{
    for(int i = 0; i < arr -> length - 1; i++)
    {
        if(arr -> ptr[i] > arr -> ptr[i + 1])
            return false;
    }
    return true;
}

// Make the negative value on the left side, the positive value on the right side.
void Rearrange(struct Array* arr)
{
    int i = 0, j = arr -> length - 1;
    while(i <= j)
    {
        while(arr -> ptr[i] < 0)
            i++;
        while (arr -> ptr[j] >= 0)
            j--;
        if(i < j)
            swap(arr -> ptr + i, arr -> ptr + j);
    }
}

// Brief: Merge arr1 and arr2 and return the merge arrays
// arr3 length = arr1 length + arr2 length
// arr3 size = arr1 size + arr2 size
// Note: the arr1 and arr2 must be sorted !
struct Array Merge(struct Array* arr1, struct Array* arr2)
{
    struct Array arr3;
    int i = 0, j = 0;
    arr3.length = arr1 -> length + arr2 -> length;
    arr3.size = arr1 -> size + arr2 -> size;
    arr3.ptr = (int*)malloc(sizeof(int) * (arr1 -> size + arr2 -> size));
    for(int k = 0; k < arr3.length - 1; k++)
    {
        if(arr1 -> ptr[i] <= arr2 -> ptr[j])
        {
            arr3.ptr[k] = arr1 -> ptr[i++];
            continue;
        }    
        if(arr2 -> ptr[j] <= arr1 -> ptr[i])
        {
            arr3.ptr[k] = arr2 -> ptr[j++];
            continue;
        }    
    }
    if (i < j)
        arr3.ptr[arr3.length - 1] = arr1 -> ptr[i];
    else    
        arr3.ptr[arr3.length - 1] = arr2 -> ptr[j];
        
    return arr3;
}

// Naive Union
// the only limited: arr1 and arr2 should not have the same elements
// return array size: arr1 size + arr2 size
// This implementation is O(n^2) complexity
struct Array Union(struct Array* arr1, struct Array* arr2)
{
    struct Array arr3;
    arr3.size = arr1 -> size + arr2 -> size;
    arr3.ptr = new int[arr3.size];
    arr3.length = arr1 -> length;
    memcpy(arr3.ptr, arr1 -> ptr, sizeof(int)* arr1 -> length);
    for(int i = 0; i < arr2 -> length; i++)
    {
        bool append = true;
        for(int j = 0; j < arr1 -> length; j++)
        {
            if(arr2 -> ptr[i] == arr1 -> ptr[j])
            {
                append = false;
                break;
            }
        }
        if(append)
            Append(&arr3, arr2 -> ptr[i]);
    }
    return arr3;
}

// Sorted Union
// The input arr1 and arr2 must be sorted and should not have the same elements.
// Return a sorted array3, which is the Union of arr1 and arr2
// This implementation is Linear complexity
struct Array Union_sorted(struct Array* arr1, struct Array* arr2)
{
    int i = 0,j = 0;
    struct Array arr3;
    arr3.size = arr1 -> size + arr2 -> size;
    arr3.length = 0;
    arr3.ptr = (int*)malloc(sizeof(int) * arr3.size);
    while(i < arr1->length && j < arr2 -> length)
    {
        if(arr1->ptr[i] < arr2->ptr[j])
            Append(&arr3, arr1->ptr[i++]);
        else if(arr1->ptr[i] > arr2->ptr[j])
            Append(&arr3, arr2->ptr[j++]);
        else
        {
            Append(&arr3, arr1->ptr[j++]);
            i++;
        }
    }
    // 过完while loop肯定会有一个arr是已经被遍历完毕了，其下标变量i/j = 其length
    // 没被遍历完的arr剩下的元素直接append到最后就可以了
    if(j < i)
    {
        for(; j < arr2->length; j++)
            Append(&arr3, arr2->ptr[j]);
    }
    else
        for(; i < arr1->length; i++)
            Append(&arr3, arr1->ptr[i]);

    return arr3;
}

// return the intersection of arr1 and arr2
// the input array should not have same elements
struct Array Intersection(struct Array* arr1, struct Array* arr2)
{
    struct Array arr3;
    arr3.size = min(arr1 -> size, arr2 -> size);
    arr3.length = 0;
    arr3.ptr = new int[arr3.size];
    for(int i = 0; i < arr1 -> length; i++)
        for(int j = 0; j < arr2 -> length; j++)
            if(arr1 -> ptr[i] == arr2 -> ptr[j])
            {
                Append(&arr3, arr1 -> ptr[i]);
                break;
            }
    return arr3;
}

// return the difference elements of arr1 - arr2
struct Array Difference(struct Array* arr1, struct Array* arr2)
{
    struct Array arr3;
    arr3.size = arr1 -> size;
    arr3.length = 0;
    arr3.ptr = new int[arr3.size];
    for(int i = 0; i < arr1 -> length; i++)
    {
        bool append = true;
        for(int j = 0; j < arr2 -> length; j++)
        {
            if(arr1->ptr[i] == arr2->ptr[j])
            {
                append = false;
                break;
            }
        }
        if(append)
            Append(&arr3, arr1->ptr[i]);
    }
    return arr3;
}