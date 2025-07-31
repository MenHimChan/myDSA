// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-28

#include "ADT.h"

int main() {
    // Chaining Hashtable Test
    int arr[] = {15, 23, 7, 8, 42, 31, 56, 77, 89, 100};
    int len = sizeof(arr) / sizeof(*arr);

    // Create() test
    HashTable<int> ht(len, Chaining);
    ht.Create(arr, len);
    ht.Display();
    ht.priv();

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
    ht.Insert(10000);
    ht.Insert(29999);               // 实测在上述基础上插入两个key就会触发扩容
    cout << "ht.Search(10000) : " << ht.Search(10000) << endl;
    cout << "ht.Search(77) : " << ht.Search(77) << endl;
    cout << "ht.Search(100) : " << ht.Search(100) << endl;
    cout << "ht.Search(31) : " << ht.Search(31) << endl;
    cout << "ht.Search(8) : " << ht.Search(8) << endl;
    ht.Display();
    ht.priv();
}

