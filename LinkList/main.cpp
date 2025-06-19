// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-12

#include "ADT.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //////////////////////////////////////////////////////// Singly LinkedList //////////////////////////////////////////////////
    // Create test
    // LinkedList<int> lkls;
    // lkls.Create(5);             
    // lkls.Display();

    // Append test
    // LinkedList<int> lkls;
    // lkls.Create(5);             
    // lkls.Display();    
    // lkls.Append(10000);
    // lkls.Display();

    // CreateByInsert test
    // LinkedList<int> lkls;
    // lkls.CreateByInsert();
    // lkls.Display();
    // lkls.PrintHeadPtr();

    // cin >> overloading test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.Reverse_RDisplay();
    // lkls.RDisplay();

    // API test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // cout << "TotalElems is: " << lkls.TotalElems() << endl;
    // cout << "RSum is: " << lkls.RSum() << endl;
    // cout << "Sum is: "<< lkls.Sum() << endl;
    // cout << "Max value is: " << lkls.Max() << endl;
    // cout << "RMax() is: " << lkls.RMax() << endl;

    // LinearSearch test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // auto node = lkls.LinearSearch(3);
    // if(node)
    //     cout << node->data << endl;
    // else
    //     cout << "couldn't find the value !!" << endl;

    // LinearSearch_improved test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // auto node2 = lkls.LinearSearch_improve(56);
    // if(node2)
    //     cout << node2->data << endl;
    // else
    //     cout << "couldn't find the value !!" << endl;
    // lkls.Display();
    // lkls.PrintHeadPtr();

    // Insert test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.Insert(4,2525);
    // lkls.Display();

    // Insert sorted tests
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.Insert_sorted(100);
    // lkls.Display();

    // Delete tests
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.Delete(2);
    // lkls.Display();

    // isSorted() test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // cout << "lkls.isSort() : " << lkls.isSorted() << endl;

    // RemoveDuplicates() test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.RemoveDuplicates();
    // lkls.Display();

    // Reverse of LinkedList by reverse value
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.Reverse_elems();
    // lkls.Display();

    // Reverse of LinkedList by reverse linked
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.Reverse_link();
    // lkls.Display();

    // Reverse of LinkedList by 
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.RReverse();
    // lkls.Display();

    // Concatenate two LinkedList
    // LinkedList<int> lkls1;
    // LinkedList<int> lkls2;
    // cin >> lkls1;
    // cin >> lkls2;
    // LinkedList<int> lkls3 = lkls1.Concatnate(lkls2);
    // lkls3.Display();

    // Concatenate two LinkedList using overloading
    // LinkedList<int> lkls1;
    // LinkedList<int> lkls2;
    // cin >> lkls1;
    // cin >> lkls2;
    // LinkedList<int> lkls3 = lkls1 + lkls2;
    // lkls3.Display();
    // lkls3.PrintHeadPtr();
    // lkls3.PrintSize();

    // Merge 2 sorted linkedlist test
    // LinkedList<int> lkls1;
    // LinkedList<int> lkls2;
    // cin >> lkls1;
    // cin >> lkls2;
    // lkls1.Merge(lkls2);
    // lkls1.Display();
    // lkls1.PrintSize();

    // isLoop() toLoop() test
    // LinkedList<int> lkls;
    // cin >> lkls;
    // lkls.Display();
    // lkls.PrintSize();
    // cout << "lkls is loop : " << lkls.isLoop() << endl;
    // cout << "--------------------- Calling lkls.toLoop(1): -------------------------" << endl;
    // lkls.toLoop(0);
    // lkls.DisplayCircular();
    // lkls.PrintHeadPtr();
    // lkls.PrintSize();
    // cout << "lkls is loop : " << lkls.isLoop() << endl;
    
    // CreateCircular() test
    // LinkedList<int> lkls;
    // lkls.CreateCircular();
    // lkls.DisplayCircular();
    // lkls.PrintHeadPtr();

    // InsertCircular() test
    // LinkedList<int> lkls;
    // lkls.CreateCircular();
    // lkls.DisplayCircular();
    // lkls.PrintHeadPtr();
    // lkls.InsertCircular(0,1000);
    // lkls.DisplayCircular();
    // lkls.PrintHeadPtr();

    // DeleteCircular() test
    // LinkedList<int> lkls;
    // lkls.CreateCircular();
    // lkls.DisplayCircular();
    // lkls.PrintHeadPtr();
    // lkls.DeleteCircular(0);
    // lkls.DisplayCircular();
    // lkls.PrintHeadPtr();

    // FindMid() test
    LinkedList<int> lkls;
    cin >> lkls;
    lkls.Display();
    auto node = lkls.FindMid();
    if(node) {
        cout << "MidNode -> data : " << node->data << endl;
        cout << "MidNode -> next : " << node->next << endl;
    }
    else
        cout << "MidNode is nullptr ! " << endl; 


    //////////////////////////////////////////////////////// DoublyLinkedList //////////////////////////////////////////////////
    // create() test
    // DoublyLinkedList<int> dll;
    // dll.Create(5);
    // dll.Display();
    // dll.PrintHeadptr();

    // TotalElems() test
    // DoublyLinkedList<int> dll;
    // dll.Create(3);
    // dll.Display();
    // cout << "dll.TotalElems() : " << dll.TotalElems() << endl;

    // Insert() test
    // DoublyLinkedList<int> dll;
    // dll.Create(3);
    // dll.Display();
    // cout << "------------------ calling the dll.Insert(0, 100) ---------------" << endl;
    // dll.Insert(3, 100);
    // dll.Display();

    // Delete() test
    // DoublyLinkedList<int> dll;
    // dll.Create(5);
    // dll.Display();
    // cout << "------------------ calling the dll.Delete(4) ---------------" << endl;
    // dll.Delete(4);
    // dll.Display();

    // Reverse() test
    // DoublyLinkedList<int> dll;
    // dll.Create(5);
    // dll.Display();
    // cout << "------------------ calling the dll.Reverse() ---------------" << endl;
    // dll.Reverse();
    // dll.Display();

    // hasLoop() test
    // DoublyLinkedList<int> dll;
    // dll.Create(5);
    // dll.Display();
    // cout << "dll.hasLoop() : " << dll.hasLoop() << endl;
    // dll.toCircular();
    // cout << "dll.hasLoop() : " << dll.hasLoop() << endl;
    // dll.Display();
    // dll.PrintHeadptr();

    // // InsertCircular() test
    // DoublyLinkedList<int> dll;
    // dll.Create(4);
    // dll.toCircular();
    // dll.Display();
    // dll.InsertCircular(0, 10000);
    // dll.Display();
    // dll.PrintHeadptr();



    return 0;
}