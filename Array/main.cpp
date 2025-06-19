// main.cpp
#include "ADT.h"
#include <iostream>
using namespace std;

// vscode compile management:
// https://chat.deepseek.com/a/chat/s/23b7423d-8fcf-44f9-9c7e-56939a94ca06

// Implementation 1
// return the missing elements
// Input must only have one missing elememts, 并且是顺序的自然数列
// eg. 1 2 3 5 7 8(missing "4")
//     4 5 6 8 9 10(missing "7")
template <class T>
int fd_One_Missing_1(ArrayClass<T>& arr)
{
    int n = arr.GetLength();
    int first = arr.Get(0);
    int last = arr.Get(n - 1);
    int expected_sum = (first + last) * (last - first + 1) / 2;
    return expected_sum - arr.Sum();
}

// Implementation 2
// return the missing elements
// Input must only have one missing elememts, 并且是顺序的自然数列
// eg. 1 2 3 5 7 8(missing "4")
//     4 5 6 8 9 10(missing "7")
template <class T>
int fd_One_Missing_2(ArrayClass<T>& arr)
{
    int delta = arr.Get(0);                     // arr[0] - 0
    for(int i = 1; i < arr.GetLength(); i++)    // arr[i] - i
        if(delta != arr.Get(i) - i)
            return i + delta;
    return -1;
}

// return the missing elements in an ArrayClass array
// Input must can have more than one missing elememts, 并且是顺序的自然数列
template <class T>
ArrayClass<T> fd_Multi_Missing(ArrayClass<T>& arr)
{
    ArrayClass<T> ret(arr.GetSize());               // 缺失值组成的数组大小肯定比原始数组要小，申请空间的时候申请大的兼容小的
    int input_len = arr.GetLength();
    int exp_num = arr.Get(input_len - 1) - arr.Get(0) + 1;      // 若未缺失，则有exp_num个数
    int missing = exp_num - input_len;              // missing elements number
    while (missing != 0)
    {
        int mis_val = fd_One_Missing_2(arr);
        ret.Append(mis_val);
        arr.Insert_sorted(mis_val);
        missing--;
    }
    return ret;
}

// Implementation 2
template <class T>
ArrayClass<T> fd_Multi_Missing_2(ArrayClass<T>& arr)
{
    ArrayClass<T> ret(arr.GetSize());               // 缺失值组成的数组大小肯定比原始数组要小，申请空间的时候申请大的兼容小的
    int diff = arr.Get(0) - 0;
    for(int i = 0; i < arr.GetLength(); i++)
    {
        if(arr.Get(i) - i != diff)
        {
            while(diff < arr.Get(i) - i)
            {
                ret.Append(i + diff);
                diff++;
            }
        }
    }
    return ret;
}

// return the multiple missing value of an array whose value ranging from low to high
template <class T>
ArrayClass<T> fd_Multi_Missing_hash(ArrayClass<T>& arr)
{
    ArrayClass<T> ret(arr.GetSize());               // 缺失值组成的数组大小肯定比原始数组要小, 用传入数组的大小给返回数组使用肯定够用
    int hash[arr.Max() + 1];
    for(int i = arr.Min(); i <= arr.Max(); i++)     
        hash[i] = 0;
    for(int i = 0; i < arr.GetLength(); i++)        
        hash[arr.Get(i)] = 1;
    for(int i = arr.Min(); i <= arr.Max(); i++)
    {
        if(hash[i] == 0)
            ret.Append(i);
    }
    return ret;
}

// finding duplicate Elements in a sorted array
// return the duplicate Elements in a new ArrayClass<T> type array
template <class T>
ArrayClass<T> fd_duplicate_1(ArrayClass<T> arr)
{
    ArrayClass<T> ret(arr.GetSize());             
    T lastdepulicate = 0;
    for(int i = 0; i < arr.GetLength() - 1; i++)        // len - 1 make sure the bound safety
    {
        if(arr.Get(i) == arr.Get(i + 1) && arr.Get(i) != lastdepulicate)
        {
            lastdepulicate = arr.Get(i);
            ret.Append(lastdepulicate);
        }
    }
    return ret;
}

// finding duplicate Elements in a sorted array
// return the duplicate Elements in a new ArrayClass<T> type array
// Inside the function it will printf the repeat elements and the times it repeat
template <class T>
ArrayClass<T> fd_duplicate_2(ArrayClass<T> arr)
{
    ArrayClass<T> ret(arr.GetSize());
    for(int i = 0; i < arr.GetLength() - 1; i++)
    {
        if(arr.Get(i) == arr.Get(i + 1))
        {
            ret.Append(arr.Get(i));
            int j = i + 1;
            while(arr.Get(i) == arr.Get(j)) j++;
            printf("num : %d repeat : %d times\n", arr.Get(i), j - i);
            i = j;
        }
    }
    return ret;
}

// finding duplicate Elements in a array(whether it is sorted or not) using hash table
// return the duplicate Elements in a new ArrayClass<T> type array
// Inside the function it will printf the repeat elements and the times it repeat
template <class T>
ArrayClass<T> fd_duplicate_hash(ArrayClass<T> arr)
{
    ArrayClass<T> ret(arr.GetSize());
    int hash_len = arr.Max() + 1;               // hash table array size should be the max elements + 1
    int hash[hash_len];                    
    for(int i = 0; i < hash_len; i++)           // Init the hash table, set all elements to 0
        hash[i] = 0;
    for(int i = 0; i < arr.GetLength(); i++)    // traversal the input array
        hash[arr.Get(i)]++;
    for(int i = arr.Min(); i <= arr.Max(); i++)
    {
        if(hash[i] > 1)
        {
            ret.Append(i);
            printf("num : %d repeat : %d times\n", i, hash[i]);
        }
    }
    return ret;                        
}

// using hash table finding 2 elements whose sum equal to K
// no matter the input array is sorted or not 
template <class T>
void fd_SumKPair_hashing(ArrayClass<T> arr, int sum)
{
    int hash_len = arr.Max() + 1;                   // hash table array size should be the max elements + 1
    int hash[hash_len];
    for(int i = 0; i < hash_len; i++)
        hash[i] = 0;          
    for(int i = 0; i < arr.GetLength(); i++)        // traverse the whole arr
    {
        if(sum - arr.Get(i) >= 0)                   // Prevent negative indexing of arrays
            if(hash[sum - arr.Get(i)] != 0)
                printf("Finding pair: arr[%d]=%d and arr[%d]=%d, which is sum: %d\n", i, arr.Get(i), arr.BinarySearch(sum - arr.Get(i)), sum - arr.Get(i), sum);
        hash[arr.Get(i)]++; 
    }          
}

int main()
{
    ////////////////////////////////////////////// C style code ///////////////////////////////////////////////////
    // fixed length of an array
    // struct Array_fixed arr;
    // arr = {{1,2,3,4,5}, 20, 5};

    // Dynamic length of arrays
    // struct Array arr;
    // cout << "Enter array size: ";
    // cin >> arr.size;

    // allocate memory, init array with enter value
    // arr.ptr = (int*)malloc(arr.size * sizeof(int));
    // cout << "Enter number of numbers: ";
    // cin >> arr.length;
    // for(int i = 0; i < arr.length; i++)
    //     cin >> arr.ptr[i];
    // Display(arr);

    // // append x into the arrays
    // Append(&arr, 10);
    // Display(arr);

    // // insert x into the arrays
    // Insert(&arr, 0, 19);        // insert "19" into index "3"
    // Display(arr);

    // // delete index elements
    // cout << "Delete elems: " << Delete(&arr, 6);
    // Display(arr);

    // // Linear Search
    // cout << "Key is in index: " << LinearSearch_imporved(&arr, 3);
    // Display(arr);

    // Binary Search
    // cout << BinarySearch(&arr, 5) << endl;
    // cout << RBinarySearch(&arr, 0, arr.length - 1, 100) << endl;

    // Max
    // cout << Max(&arr) << endl;

    // Avg
    // cout << Avg(&arr) << endl;

    // Reverse 
    // Reverse_swap(&arr);
    // Display(arr);

    // left shirft
    // lshirft(&arr);
    // Display(arr);

    // left rotate
    // lrotat(&arr);
    // Display(arr);

    // Insert in a sorted array
    // Insert_sorted(&arr, 18);
    // Display(arr);

    // Check if the array is sorted or not
    // cout << isSorted(&arr);

    // Rearrange the array
    // Rearrange(&arr);
    // Display(arr);

    // Merge the sorted array
    // struct Array arr2;
    // arr2.length = 3;
    // arr2.size = 5;
    // arr2.ptr = new int[arr2.size]{1,2,4};
    // Array arr3 = Merge(&arr, &arr2);
    // Display(arr3);

    // Union arr1 arr2
    // struct Array arr2;
    // arr2.length = 5;
    // arr2.size = 10;
    // arr2.ptr = new int[arr2.size]{4,5,7,2,3};
    // Array arr3 = Union(&arr, &arr2);
    // Display(arr3);

    // Union arr1 arr2
    // struct Array arr2;
    // arr2.length = 5;
    // arr2.size = 10;
    // arr2.ptr = new int[arr2.size]{3,4,5,6,10};
    // Array arr3 = Union_sorted(&arr, &arr2);
    // Display(arr3);

    // Intersection arr1 arr2
    // struct Array arr2;
    // arr2.length = 4;
    // arr2.size = 5;
    // arr2.ptr = new int[arr2.size]{1,2,4,7};
    // Array arr3 = Intersection(&arr, &arr2);
    // Display(arr3);

    // Difference: arr1 - arr2
    // struct Array arr2;
    // arr2.length = 4;
    // arr2.size = 5;
    // arr2.ptr = new int[arr2.size]{4,5,7,6};
    // Array arr3 = Difference(&arr, &arr2);
    // Display(arr3);

    ////////////////////////////////////////////// C++ style code ///////////////////////////////////////////////////
    // ArrayClass arr1(10), arr2(20);
    // arr1.SetArray(5);
    // arr2.SetArray(5);
    // cout << arr1.GetSize();
    // arr1.Append(100);
    // arr1.Insert(4, 100);
    // cout << arr1.Delete(2) << endl; 
    // cout << arr1.LinearSearch(100) << endl;
    // cout << arr1.BinarySearch(1) << endl;
    // arr1.Reverse_swap();
    // arr1.lrotat();
    // arr1.Rearrange();
    // ArrayClass arr3 = ArrayClass::Union(arr1, arr2);
    // ArrayClass arr3 = ArrayClass::Merge(arr1, arr2);
    // ArrayClass arr3 = ArrayClass::Intersection(arr1, arr2);
    // cout << arr3.GetSize() << endl;
    // cout << arr3.GetLength() << endl;
    // arr3.Display();

    //////////////////////////////////////// Meun Driven template class test////////////////////////////////////////
    // ArrayClass<float> arr1(10), arr2(20);
    // arr1.SetArray(5);
    // arr2.SetArray(5);
    // cout << "The first array: "; arr1.Display();
    // cout << "The second array: "; arr2.Display();    

    // short choice;
    // for(int t = 0; t < 5; t++)
    // {
    //     cout << "\nMenu:\n";
    //     cout << "1. Append to arr1\n";
    //     cout << "2. Insert into arr1\n";
    //     cout << "3. Delete from arr1\n";
    //     cout << "4. Merge arr1 and arr2\n";
    //     cout << "5. Union arr1 and arr2\n";
    //     cout << "6. Intersection arr1 and arr2\n";
    //     cout << "7. Difference arr1 - arr2\n";
    //     cout << "0. Exit\n";
    //     cout << "Enter your choice: ";
    //     cin >> choice;

    //     switch(choice)
    //     {
    //         case 1:
    //         {
    //             float x;
    //             cout << "Enter value u want to append: ";
    //             cin >> x;
    //             arr1.Append(x);
    //             arr1.Display();
    //             break;
    //         }

    //         case 2:
    //         {
    //             int idx;
    //             float x;
    //             cout << "Enter index and value to insert: ";
    //             cin >> idx >> x;
    //             arr1.Insert(idx, x);
    //             arr1.Display();
    //             break;
    //         }

    //         case 3:
    //         {
    //             int idx;
    //             cout << "Enter index to delete: ";
    //             cin >> idx;
    //             arr1.Delete(idx);
    //             arr1.Display();
    //             break;
    //         }

    //         case 4:
    //         {
    //             ArrayClass<float> arr3 = ArrayClass<float>::Merge(arr1, arr2);
    //             cout << "Merged array: ";
    //             arr3.Display();
    //             break;
    //         }

    //         case 5: 
    //         {
    //             ArrayClass<float> arr3 = ArrayClass<float>::Union(arr1, arr2);
    //             cout << "Union array: ";
    //             arr3.Display();
    //             break;
    //         }
                    
    //         case 6: 
    //         {
    //             ArrayClass<float> arr3 = ArrayClass<float>::Intersection(arr1, arr2);
    //             cout << "Intersection array: ";
    //             arr3.Display();
    //             break;
    //         }
                    
    //         case 7: 
    //         {
    //             ArrayClass<float> arr3 = ArrayClass<float>::Difference(arr1, arr2);
    //             cout << "Difference array: ";
    //             arr3.Display();
    //             break;
    //         }
                    
    //         case 0:
    //         {
    //             cout << "Exit.\n";
    //             t = 5; // 直接跳出循环
    //             break;
    //         }

    //         default:
    //             cout << "Invalid choice.\n";
    //     }
    // }

    ///////////////////////// Finding missing elements //////////////////////
    // Find multiple missing values in an ordered natural number sequence. Implementation 1
    // ArrayClass<int> arr_in(15);
    // arr_in.SetArray(5);
    // ArrayClass<int> arr_out = fd_Multi_Missing<int>(arr_in);            // arr_out hold the missing elements
    // arr_out.Display();  
    // arr_in.Display();

    // Find multiple missing values in an ordered natural number sequence. Implementation 2
    // ArrayClass<int> arr_in(15);
    // arr_in.SetArray(5);
    // ArrayClass<int> arr_out = fd_Multi_Missing_2<int>(arr_in);            // arr_out hold the missing elements
    // arr_out.Display();  
    // arr_in.Display();

    // Find multiple missing values in an disorder natural number sequence using bitset
    // ArrayClass<int> arr_in(15);
    // arr_in.SetArray(10);
    // ArrayClass<int> arr_out = fd_Multi_Missing_hash<int>(arr_in);
    // arr_out.Display();

    // Find dupulicate elements: method 1
    // ArrayClass<int> arr_in(15);
    // arr_in.SetArray(10);
    // ArrayClass<int> arr_out = fd_duplicate_1<int>(arr_in);
    // arr_out.Display();    

    // Find dupulicate elements: method 2
    // ArrayClass<int> arr_in(15);
    // arr_in.SetArray(10);
    // ArrayClass<int> arr_out = fd_duplicate_2<int>(arr_in);
    // arr_out.Display();   

    // Find dupulicate elements: hash table
    // ArrayClass<int> arr_in(15);
    // arr_in.SetArray(10);
    // ArrayClass<int> arr_out = fd_duplicate_hash<int>(arr_in);
    // arr_out.Display();   

    // Find sum k pair using hash table
    ArrayClass<int> arr_in(15);
    arr_in.SetArray(10);
    arr_in.Display();
    fd_SumKPair_hashing(arr_in, 10);    
}

