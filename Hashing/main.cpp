// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-28

#include "ADT.h"

int main() {
    // ================================= Chaining Hashtable Test =================================
    // int arr[] = {15, 23, 7, 8, 42, 31, 56, 77, 89, 100};
    // int len = sizeof(arr) / sizeof(*arr);

    // Create() test
    // HashTable<int> ht(len, Chaining);
    // ht.Create(arr, len);
    // ht.Display();
    // ht.priv();

    // .Search() test, using keys to search in the hashtable
    // cout << "ht.Search(7) : " << ht.Search(7) << endl;
    // cout << "ht.Search(100) : " << ht.Search(100) << endl;
    // cout << "ht.Search(31) : " << ht.Search(31) << endl;
    // cout << "ht.Search(11) : " << ht.Search(11) << endl;

    // Display test
    // ht.Display();
    // ht.priv();

    // ResizeAndReHash() test
    // ht.Display();
    // ht.priv();
    // ht.ResizeAndReHash();
    // ht.Display();
    // ht.priv();

    // Insert() test
    // ht.Insert(10000);
    // ht.Insert(29999);               // 实测在上述基础上插入两个key就会触发扩容
    // cout << "ht.Search(10000) : " << ht.Search(10000) << endl;
    // cout << "ht.Search(77) : " << ht.Search(77) << endl;
    // cout << "ht.Search(100) : " << ht.Search(100) << endl;
    // cout << "ht.Search(31) : " << ht.Search(31) << endl;
    // cout << "ht.Search(8) : " << ht.Search(8) << endl;
    // ht.Display();
    // ht.priv();

    // Delete() basic test
    // cout << "ht.Search(7) : " << ht.Search(7) << endl;
    // ht.Delete(7);
    // cout << "ht.Search(7) : " << ht.Search(7) << endl;
    // ht.Display();

    // delete after insert test
    // ht.Insert(10000);
    // ht.Insert(29999);               // 实测在上述基础上插入两个key就会触发扩容
    // cout << "ht.Search(10000) : " << ht.Search(10000) << endl;
    // cout << "ht.Search(77) : " << ht.Search(77) << endl;
    // cout << "ht.Search(100) : " << ht.Search(100) << endl;
    // cout << "ht.Search(31) : " << ht.Search(31) << endl;
    // cout << "ht.Search(8) : " << ht.Search(8) << endl;
    // ht.Display();
    // ht.priv();
    // ht.Delete(77);
    // ht.Delete(31);
    // ht.Display();
    // ht.priv();

    // ======================= LinearProbe Hashtable Test =======================
    // int arr[] = {15, 23, 7, 8, 42, 31, 56, 77, 89, 100};
    // int arr[] = {3, 6, 9, 12, 15};                               // 让它们哈希到同一个位置
    // int len = sizeof(arr) / sizeof(*arr);   

    // create test
    // HashTable<int> ht(len, LinearProbe);
    // ht.Create(arr, len);
    // ht.Display();
    // ht.priv();

    // Search test: 判断能否越过DELETED值找到key
    // 需要用到的key：3, 6, 9, 12, 15
    // ht.Delete(6); // 删除中间元素
    // ht.Display();
    // ht.priv();
    // // Display test
    // cout << "ht.Search(9) : " << ht.Search(9) << endl; // 能查找到9
    // return 0;

    // Search test
    // cout << "ht.Search(3) : " << ht.Search(3) << endl;
    // cout << "ht.Search(6) : " << ht.Search(6) << endl;
    // cout << "ht.Search(9) : " << ht.Search(9) << endl;
    // cout << "ht.Search(12) : " << ht.Search(12) << endl;
    // cout << "ht.Search(15) : " << ht.Search(15) << endl;
    // cout << "ht.Search(23) : " << ht.Search(23) << endl;

    // Insert and delete test
    // First Insert() test
    // ht.Insert(10000);
    // ht.Insert(29999);               // 实测在上述基础上插入两个key就会触发扩容
    // cout << "ht.Search(10000) : " << ht.Search(10000) << endl;
    // cout << "ht.Search(77) : " << ht.Search(77) << endl;
    // cout << "ht.Search(100) : " << ht.Search(100) << endl;
    // cout << "ht.Search(31) : " << ht.Search(31) << endl;
    // cout << "ht.Search(8) : " << ht.Search(8) << endl;
    // ht.Display();
    // ht.priv();

    // delete test
    // ht.Delete(77);
    // ht.Delete(31);
    // ht.Display();
    // ht.priv();

    // ======================= QuadraticProbe Hashtable Test =======================
    int arr[] = {12, 23, 34, 45};                       // 这些数 key % 11 都等于1，会发生多次冲突
    int len = sizeof(arr) / sizeof(*arr);

    // create() test
    HashTable<int> ht(len, QuadraticProbe);
    ht.Create(arr, len);
    ht.Display();
    ht.priv();

    // delete() test
    // ht.Delete(34);
    // ht.Display();
    // ht.priv();

    // Search() test
    // cout << "ht.Search(45) : " << ht.Search(45) << endl;
    // cout << "ht.Search(199) : " << ht.Search(199) << endl;
    // cout << "ht.Search(14) : " << ht.Search(14) << endl;

    // Insert() test
    ht.Insert(56);
    ht.Display();
    ht.priv();

    ht.Insert(67);
    ht.Display();
    ht.priv();

}

