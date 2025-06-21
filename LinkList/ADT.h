// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-14

// ADT.h
#ifndef ADT_H  // 防止头文件重复包含
#define ADT_H
#include <iostream>
#include <unordered_set>
using namespace std;

// 前向声明
template <typename T> class LinkedList;
template <typename T> std::istream& operator>>(std::istream& is, LinkedList<T>& ll);
template <class T> LinkedList<T> operator+(const LinkedList<T>& a, const LinkedList<T>& b);

template <class T>
class LinkedList
{
    private:
        struct Node{
            T data;
            Node* next;
        };
        int size;
        Node* head;
        void RDisplay(Node* p) const;
        void Reverse_RDisplay(Node* p) const; 
        void RReverse(Node* curr, Node* prev);
        T RSum(Node* p) const;
        T RMax(Node* p) const;

    public:
        LinkedList();                                                                 // default constructor
        LinkedList(int size);                                                         // constructor with size   
        LinkedList(const LinkedList<T>& other);                                       // copy constructor
        ~LinkedList();
        friend std::istream& operator>> <>(std::istream& is, LinkedList<T>& ll);      // Input methed: the first is the length of the linkedlist, following is elems
        friend LinkedList<T> operator+ <>(const LinkedList<T>& a, const LinkedList<T>& b);        // concat a and b
        void PrintHeadPtr() const {cout << "Head addr is : " << head << endl;}        // Print the head pointer
        Node* GetHead() {return head;}
        void PrintSize() const {cout << "LinkedList size is : " << size << endl;}     // Print the size
        void Create(int size);
        void toLoop(int index);                                                       // Create a loop linkedlist by setting: last->next = index node
        void CreateByInsert();                                                        // Create a linkedlist by calling insert function
        void Display();                                       // Display function implemented by while loop
        int TotalElems() const;                               // return the numbers of elements by Traversal
        void Insert(int index, T x);                          // Insert the x to the index posistion, valid value for index is: (0 ~ size)
        void Insert_sorted(T x);                              // Insert x into a sorted linkedlist
        void Append(T x);                                     // Append the x value to the end of the linkedlist
        void Delete(int index);                               // Delete the index node, number is from small to big, eg: 1 3 5 6 7 8
        bool isSorted();                                      // check the linkedlist is sorted or not 
        bool isLoop();                                        // check the linkedlist is sorted or not
        void RemoveDuplicates();                              // Remove duplicate elements of the LinkedList
        void Reverse_elems();                                 // Reverse the linkedlist by reverse the value
        void Reverse_link();                                  // Reverse the linkedlist by reverse the linked
        void RReverse() {RReverse(head, nullptr);}            // Reverse the linkedlist by recursion
        void RDisplay(){RDisplay(head);}                      // Recurive version of Display
        void Reverse_RDisplay(){Reverse_RDisplay(head);}      // Reverse Display implemented by the Recursion
        LinkedList<T> Concatnate(const LinkedList<T>& other); // Concatnate the linkedlist with others
        T RSum(){return RSum(head);}  
        T Sum() const;                                        // return sum of the whole LinkedList
        T RMax(){return RMax(head);}
        T Max() const;                                        // return Max elems of the whole LinkedList
        void Merge(const LinkedList<T>& other);
        typename LinkedList<T>::Node* LinearSearch(T key);    // return the ptr to the key elements node
        LinkedList<T>::Node* LinearSearch_improve(T key);     // return the ptr to the key elements node and put the key node to the first place
        LinkedList<T>::Node* FindMid();                       // return the middle node of the whole LinkedList

        // Here is for circular linkedlist
        void CreateCircular() {cin >> *this; toLoop(0);}                              // create circular LinkedList
        void DisplayCircular();                                                       // Display a circular linkedlist
        // @brief: Insert in a circular LinkedList, the index is 0~size.
        // @example: index = 1, x = 1000 <=> insert 1000 before the node index 1, index 0 means the head node
        void InsertCircular(int index, T x);       
        void DeleteCircular(int index);             
};

template <class T>
LinkedList<T>::LinkedList()
{
    this->size = 0;
    this->head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(int size)
{
    this->size = size;
    this->head = nullptr;
}

// copy construtor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    size = other.size;
    head = nullptr;
    Node* curr = other.head;
    Node* tail = nullptr;
    while(curr != nullptr)
    {
        Node* newnode = new Node{curr->data, nullptr};
        if(head == nullptr)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        curr = curr->next;
    }
}

// template <class T>
// LinkedList<T>::~LinkedList()
// {
//     while(head)
//     {
//         Node* tmp = head;
//         head = head->next;
//         delete tmp;
//     }
// }
template <class T>
LinkedList<T>::~LinkedList()
{
    std::unordered_set<Node*> visited;
    while(head)
    {
        if(visited.count(head)) break; // 已经访问过，说明有环，退出
        visited.insert(head);
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <class T>
int LinkedList<T>::TotalElems() const
{
    int cnt = 0;
    Node* p = head;
    while(p != nullptr)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

template <class T>
std::istream& operator>>(std::istream& is, LinkedList<T>& ll)
{
    // delete current LinkedList
    while(ll.head != nullptr)
    {
        typename LinkedList<T>::Node* tmp = ll.head;
        ll.head = ll.head->next;
        delete tmp;
    }
    ll.size = 0;
    
    // Input size of the LinkedList
    is >> ll.size;

    // Build the LinkedList
    typename LinkedList<T>::Node* tail = nullptr;
    for(int i = 0; i < ll.size; i++)
    {
        T val;
        is >> val;

        typename LinkedList<T>::Node* newnode = new typename LinkedList<T>::Node{val, nullptr};
        if(ll.head == nullptr)
        {
            ll.head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return is;
}

template <class T>
void LinkedList<T>::Create(int size)
{
    // Init the linkedlist
    this->size = size;
    this->head = nullptr;

    Node* tail = nullptr;
    for(int i = 0; i < size; i++)
    {
        T val;
        cout << "Plz input index " << i << " number: ";
        cin >> val;
        Node* newnode = new Node{val, nullptr};
        if(head == nullptr)                     // 首次插入节点，head, tail均指向第一个node
        {
            head = newnode;
            tail = newnode;
        }
        else                                    // 非首次插入节点
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
}

template <class T>
void LinkedList<T>::DisplayCircular() 
{
    if(isLoop())
    {
        int cnt = 0;
        Node* p = head;
        do{
            cout << "[" << p->data << " | " << p->next << "]";
            if(cnt != this->size - 1)
                cout << " -> ";
            p = p->next;
            cnt++;
        }while(p != head);
        cout << endl;
    }
    else
        cout << "This isn't a Circular LinkedList ! Don't use this api !" << endl;
}

template <class T>
void LinkedList<T>::Display()
{
    if(!isLoop())
    {
        cout << "The Linear Linked list is : \n";
        for(Node* p = head; p != nullptr; p = p->next)
        {
            cout << "[" << p->data << " | ";
            if(p->next != nullptr)
                cout << p->next << "]";
            else
                cout << "nullptr]";
            
            if(p->next != nullptr)
                cout << " -> ";
        }
        cout << '\n';
    }
    else
    {
        int i = 0;
        Node* p = head;
        cout << "The Loop Linked list is : \n";
        for(Node* p = head; p != nullptr && i < size; p = p->next, i++)
        {
            cout << "[" << p->data << " | " << p->next << "]";
            if(i != this->size - 1)
                cout << " -> ";    
        }
        cout << endl;
    }
}

template <class T>
void LinkedList<T>::RDisplay(Node* p) const
{
    if(p == nullptr)
    {
        cout << '\n';
        return;
    }
    cout << p->data << ' ';
    RDisplay(p->next);
}

template <class T>
void LinkedList<T>::Reverse_RDisplay(Node* p) const
{
    if(p == nullptr)
        return;
    else
    {
        Reverse_RDisplay(p->next);
        cout << p->data << ' ';
        if(p == head)
            cout << endl;
    }
}

template <class T>
T LinkedList<T>::RSum(Node* p) const
{
    if(p == nullptr)
        return 0;
    else
        return p->data + RSum(p->next);
}

template <class T>
T LinkedList<T>::Sum() const
{
    T sum = 0;
    Node* p = head;
    while(p != nullptr)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

template <class T>
T LinkedList<T>::Max() const
{
    T max = head->data;
    Node* p = head;
    while(p != nullptr)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

template <class T>
T LinkedList<T>::RMax(Node* p) const
{
    T ret;
    if(p == nullptr)
        return INT32_MIN;
    else
    {
        ret = RMax(p->next);
        if(ret > p->data)
            return ret;
        else
            return p->data;
    }
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::LinearSearch(T key)
{
    Node* p = head;
    while(p != nullptr)
    {
        if(p->data == key)
            return p;
        p=p->next;
    }
    return nullptr;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::LinearSearch_improve(T key)
{
    Node* q = nullptr;                      // Tail pointer following the head pointer
    Node* p = head;                         // head pointer
    while(p != nullptr)
    {
        if(p->data == key)                  // find the key elements and move it to the front of the linkedlist
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }

    return nullptr;
}

template <class T>
void LinkedList<T>::Insert(int index, T x)
{
    Node* newnode;
    Node* p;                                           // iterator
    Node* q;
    if(index == 0)                                     // Insert x to the beginning of the LinkedList
    {
        newnode = new Node{x, head};
        head = newnode;
    }

    else if(index == TotalElems())                    // Insert x to the end of the LinkedList
    {
        p = head;
        while(p->next != nullptr) p=p->next;          // go to the last node
        newnode = new Node{x, nullptr};             
        p->next = newnode;
    }

    else
    {
        int t = index - 1;
        p = head;
        q = head;
        while(index--)  p=p->next;                  // 2 ptr scan the linkedlist, p is followed by q.
        while(t--)  q=q->next;    
        newnode = new Node{x, p};
        q->next = newnode;
    }
    size++;
}

template <class T>
void LinkedList<T>::Append(T x)
{
    Node* newnode = new Node{x, nullptr};
    if(head == nullptr)                         // 如果传入的是空链表(size = 0, head = nullptr)
        head = newnode;
    else
    {
        Node* p;
        for(p = head; p->next != nullptr; p = p->next);
        p->next = newnode;
    }
    size++;
}

template <class T>
void LinkedList<T>::CreateByInsert()
{
    int n;
    cout << "Plz input the length of LinkedList: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        T val;
        cout << "Plz input index " << i << " elements: ";
        cin >> val;
        Insert(i, val);
    }
}

template <class T>
void LinkedList<T>::Insert_sorted(T x)
{
    if(x < head->data)                                      // x smaller than the first element, insert into the first place
    {
        Node* newnode = new Node{x, head};
        head = newnode;
        size++;

    }
    else if(x > Max())                                      // x larger than the last element, insert to the last place
    {
        // for(Node* p = head; p->next != nullptr; p=p->next);
        // Node* newnode = new Node{x, nullptr};
        // p = newnode;
        Append(x);
    }
    else
    {
        // int cnt;
        // Node* p = head;             
        // Node* q = head;                                     // q是p的前驱指针
        // for(cnt = 0; p->data < x; p=p->next, cnt++);
        // cnt--;
        // while(cnt--) q=q->next;                             // move q to the last one position of p
        // Node* newnode = new Node{x, p};
        // q->next = newnode;

        Node* p = head;
        Node* q = nullptr;
        for(; p->data < x && p != nullptr; q = p, p = p->next);
        Node* newnode = new Node{x, p};
        q->next = newnode;
        size++;
    }
}

template <class T>
void LinkedList<T>::Delete(int index)
{
    if(index >= 0 && index < TotalElems())
    {
        if(index == 0)                          // delete the first node
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        else if(index == TotalElems() - 1)      // delete the last node
        {
            Node *p = head, *q = nullptr;
            for(; p->next != nullptr; q = p, p=p->next);
            q->next = nullptr;
            delete p;
        }
        else
        {
            Node *p = head, *q = nullptr;
            for(int i = 0; i < index; q = p, p=p->next, i++);
            q->next = p->next;
            delete p;
        }
        size--;
    }
    else
        cout << "illegal index input !" << endl;
}

template <class T>
bool LinkedList<T>::isSorted()
{
    Node* p = head->next;
    Node* q = head;
    for(; p->next != nullptr; q = p, p = p->next)
        if(q->data > p->data)
            return false;
    return true;
}                      

template <class T>
void LinkedList<T>::RemoveDuplicates()
{
    int hash[Max() + 1];
    for(int i = 0; i < Max() + 1; i++)
        hash[i] = 0;
    Node *p = head, *q = nullptr;
    while(p != nullptr)
    {
        if(hash[p->data])                       // 已经出现过，删除当前的节点
        {
            Node* tmp = p;
            p = p->next;
            q->next = tmp->next;
            delete tmp;
            size--;
        }
        else                                    // 将对于hash table中的值置为1
        {
            hash[p->data]++;
            q = p;
            p = p->next;
        }
    }
}

template <class T>
void LinkedList<T>::Reverse_elems()
{
    T arr[TotalElems()];
    Node* p = head;
    for(int i = 0; p != nullptr; i++, p = p->next)
        arr[i] = p->data;

    p = head;
    for(int i = TotalElems() - 1; i >= 0; i--, p = p->next)
        p->data = arr[i];
}

template <class T>
void LinkedList<T>::Reverse_link()
{
    // 三指针法
    Node *curr = head, *prev = nullptr, *next  = nullptr;
    for(; curr != nullptr; next = curr->next, curr->next = prev, prev = curr, curr = next);  
    head = prev;
}

// 递归实现链表反转
template <class T>
void LinkedList<T>::RReverse(Node* curr, Node* prev)
{
    if(curr == nullptr)
    {
        head = prev;
        return;
    }
    RReverse(curr->next, curr);
    curr->next = prev;
}

template <class T>
LinkedList<T> LinkedList<T>::Concatnate(const LinkedList<T>& other)
{
    LinkedList<T> ret;
    Node* curr = this->head;
    Node* tail = nullptr;

    while(curr != nullptr)
    {
        Node* newnode = new Node{curr->data, nullptr};
        if(ret.head == nullptr)
        {
            ret.head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        curr = curr->next;
        ret.size++;
    }

    curr = other.head;
    while(curr != nullptr)
    {
        Node* newnode = new Node{curr->data, nullptr};
        if(ret.head == nullptr)
        {
            ret.head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        curr = curr->next;
        ret.size++;
    }

    return ret;
}

template <class T>
LinkedList<T> operator+(const LinkedList<T>& a, const LinkedList<T>& b)
{
    LinkedList<T> ret;
    typename LinkedList<T>::Node* p;
    
    for(p = a.head; p != nullptr; p = p->next)
        ret.Append(p->data);

    for(p = b.head; p != nullptr; p = p->next)
        ret.Append(p->data);

    return ret;
}

template <class T>
void LinkedList<T>::Merge(const LinkedList<T>& other)
{
    // 1. 创建当前链表的深拷贝副本
    LinkedList<T> copyThis = *this;  // 调用拷贝构造函数
    
    // 2. 创建 other 链表的深拷贝副本
    LinkedList<T> copyOther = other; // 调用拷贝构造函数
    
    // 3. 在副本上执行合并操作
    Node* first = copyThis.head;
    Node* second = copyOther.head;
    Node* last = nullptr;
    
    // 处理空链表情况
    if (first == nullptr) 
    {
        copyThis.head = second;
        copyThis.size = copyOther.size;
    } 
    else if(second == nullptr) {}
    else
    {
        // 原始合并逻辑（在副本上操作）
        if (first->data < second->data) 
        {
            copyThis.head = first;              // 以第一个链表的head作为最终链表的head
            Node* tmp = first;
            first = first->next;
            tmp->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        } 
        else 
        {
            copyThis.head = second;
            Node* tmp = second;
            second = second->next;
            tmp->next = first;
            last = first;
            first = first->next;
            last->next = nullptr;
        }

        while (first != nullptr && second != nullptr) 
        {
            if (second->data < first->data) 
            {
                Node* tmp = second;
                second = second->next;
                last->next = tmp;
                tmp->next = nullptr;
                last = tmp;
            }
            else
            {
                Node* tmp = first;
                first = first->next;
                last->next = tmp;
                tmp->next = nullptr;
                last = tmp;
            }
        }

        if (first != nullptr)
            last->next = first;
        else
            last->next = second;
        
        copyThis.size = copyThis.TotalElems();
    }
    
    // 4. 转移副本所有权到当前链表
    // 防止副本析构时删除节点
    this->head = copyThis.head;
    this->size = copyThis.size;
    
    // 5. 使副本放弃节点所有权
    copyThis.head = nullptr;
    copyOther.head = nullptr;
}

template <class T>
bool LinkedList<T>::isLoop()
{
    Node* slow = this->head;
    Node* fast = this->head;
    while(slow && fast)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast != nullptr)
            fast = fast->next;
        else
            fast = nullptr;
        if(fast == slow)
            return true;
    }
    return false;
}

template <class T>
void LinkedList<T>::toLoop(int index)
{
    Node* last;
    Node* tgt_node = this->head;
    for(last = this->head; last->next != nullptr; last = last->next);
    while(index--)  tgt_node = tgt_node->next;
    last->next = tgt_node;
}

template <class T>
void LinkedList<T>::InsertCircular(int index, T x)
{
    if(index >= 0 && index <= this->size)                // check validity
    {
        if(index >= 1 && index <= this->size - 1)        // Insert at other node except head 
        {
            Node* prev = nullptr, *curr = head;
            Node* newnode = new Node{x, nullptr};
            for(; index > 0; prev = curr, curr = curr->next, index--);
            prev->next = newnode;
            newnode->next = curr;
        }     
        else                                             // Insert at the head node 
        {
            index = this->size;
            Node* prev = nullptr, *curr = head;
            Node* newnode = new Node{x, nullptr};
            for(; index > 0; prev = curr, curr = curr->next, index--);
            prev->next = newnode;
            newnode->next = curr;
            head = newnode;
        }
        this->size++;
    }
    else
        cout << "Invalid Indexing !! the index must be 0~this.size !!";
}

template <class T>
void LinkedList<T>::DeleteCircular(int index)
{
    if(index >= 0 && index <= this->size - 1)                // check validity
    {
        if(index != 0)
        {
            Node *curr = head, *prev = nullptr;
            for(; index > 0; prev = curr, curr = curr->next, index--);
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            Node* todelete = this->head;
            Node* headnext = this->head->next;
            Node* p = head;
            while(p->next != head) p = p->next;
            p->next = head->next;
            this->head = headnext;
            delete todelete;
        }
        this->size--;
    }
}

// Find the middle node at a single scan
template <class T>
typename LinkedList<T>::Node* LinkedList<T>::FindMid() {
    Node* fast = this->head;
    Node* slow = this->head;
    while(fast != nullptr) {
        fast = fast->next;
        if(fast != nullptr) 
            fast = fast->next;
        else
            break;
        slow = slow->next;
    }
    return slow;
}

template <class T>
class DoublyLinkedList
{
    private:
        struct Node{
            Node* prev;
            T data;
            Node* next;
        };
        int size;
        Node* head;

    public:
        DoublyLinkedList();
        DoublyLinkedList(int size);
        ~DoublyLinkedList();
        void Create(int size);
        int TotalElems();
        void Insert(int index, T x);
        void Delete(int index);
        void Display();
        void Reverse();
        void toCircular();
        bool hasLoop();
        void InsertCircular(int index, T x);
        void PrintHeadptr() {cout << "The HeadPtr is : " << this->head << endl;}
    
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->size = 0;
    this->head = nullptr;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(int size)
{
    this->size = size;
    this->head = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    if(!hasLoop()) {
        // 普通链表，正常释放
        while(head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    } 
    else {
        // 循环链表，先找到环的入口
        Node* slow = head;
        Node* fast = head;
        // 1. 快慢指针相遇
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);

        // 2. 找到环的入口
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        Node* loopEntry = slow;

        // 3. 释放环外节点
        Node* p = head;
        while(p != loopEntry) {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }

        // 4. 释放环上的节点（只遍历一圈）
        Node* q = loopEntry->next;
        delete loopEntry;
        while(q != loopEntry) {
            Node* tmp = q;
            q = q->next;
            delete tmp;
        }
    }
}

template <class T>
void DoublyLinkedList<T>::Create(int size)
{
    Node* last = nullptr;
    cout << "The size you want of the doubly LinkedList by para pass in is : " << size << endl;
    // cin >> this->size;
    this->size = size;
    for(int i = 0; i < this->size; i++)
    {
        T val;
        cout << "Input the index: [" << i << "] node value: "; 
        cin >> val;
        Node* newnode = new Node{nullptr, val, nullptr};
        if(head == nullptr)
        {
            head = newnode;
            last = newnode;
        }
        else
        {
            newnode->prev = last;
            last->next = newnode;
            last = newnode;
        }
    }
}

template <class T>
void DoublyLinkedList<T>::Display() {
    if(!hasLoop()) {
        cout << "The Doubly Linked list is : \n";
        for(Node* p = head; p != nullptr; p = p->next) {
            cout << "[";
            if(p->prev == nullptr)
                cout << "nullptr" << " | ";
            else
                cout << p->prev << " | ";
            cout << p->data << " | ";
            if(p->next == nullptr)
                cout << "nullptr" << "]";
            else
                cout << p->next << "] ";

            if(p->next != nullptr)
                cout << "<--> ";
        }
        cout << '\n';
    }
    else {
        cout << "The Circular Doubly Linked list is : \n";
        Node* p = head;
        int cnt = 0;
        do {
            cout << "[";
            if(p->prev == nullptr)
                cout << "nullptr" << " | ";
            else
                cout << p->prev << " | ";
            cout << p->data << " | ";
            if(p->next == nullptr)
                cout << "nullptr" << "]";
            else
                cout << p->next << "] ";

            if(cnt != this->size - 1)
                cout << "<--> ";
            p = p->next;
            cnt++;
        } while(p != head && cnt < this->size);
        cout << '\n';
    }
}

template <class T>
int DoublyLinkedList<T>::TotalElems() {
    int cnt = 0;
    for(Node* p = head; p != nullptr; p = p->next)
        cnt++;
    return cnt;
}

template <class T>
void DoublyLinkedList<T>::Insert(int index, T x) {
    if(this->head != nullptr) {
        if(index >= 0 && index <= TotalElems()) {
            if(index == 0) {
                Node* newnode = new Node{nullptr, x, this->head};
                this->head->prev = newnode;
                this->head = newnode;
            }
            else if(index == TotalElems()) {
                Node* p = this->head;
                for(; p->next != nullptr; p=p->next);
                Node* newnode = new Node{p, x, nullptr};
                p->next = newnode;
            }
            else {
                Node* p = this->head;
                while(index--) p=p->next;
                Node* newnode = new Node{p->prev, x, p};
                p->prev->next = newnode;
                p->prev = newnode;
            }
            this->size++;
        }
        else 
            cout << "Invalid Index you have input !" << endl;
    }
    else
        cout << "The Doubly LinkedList is empty ! You must Init the LinkedList before insert operation !! " << endl;
}

template <class T>
void DoublyLinkedList<T>::Delete(int index) {
    if(index >= 0 && index <= this->size - 1) {
        if(index == 0) {
            Node* p = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete p;
        }
        else if(index == this->size - 1) {
            Node* p = this->head;
            for(; p->next != nullptr; p=p->next);
            p->prev->next = nullptr;
            delete p;
        }
        else {
            Node* p = this->head;
            while(index--) p=p->next;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
    }
    else
        cout << "Invalid Index You have input !" << endl;
}

template <class T>
void DoublyLinkedList<T>::Reverse() {
    Node* curr = this->head;
    Node* next = nullptr;
    int cnt = 0;
    while(curr != nullptr) {
        if(cnt == this->size - 1)
            this->head = curr;
        next = curr->next;
        Node* tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = next;
        cnt++;
    }
}

template <class T>
void DoublyLinkedList<T>::toCircular() {
    Node* p = this->head;
    for(; p->next != nullptr; p=p->next);
    p->next = head;
    p->next->prev = p;
}

template <class T>
bool DoublyLinkedList<T>::hasLoop() {
    Node* fast = this->head;
    Node* slow = this->head;
    while(fast && slow) {
        slow = slow->next;
        fast = fast->next;
        if(fast != nullptr)
            fast = fast->next;
        if(fast == slow)
            return true;
    }
    return false;
}

template <class T>
void DoublyLinkedList<T>::InsertCircular(int index, T x) {
    if(hasLoop()) {
        if(index >= 0 && index <= this->size) {
            if(index == 0 || index == this->size) {
                Node* newnode = new Node{this->head->prev, x, this->head};
                this->head->prev->next = newnode;
                this->head->prev = newnode;
                this->head = newnode;
            }
        }
        else {
            Node* p = head;
            while(index--) p=p->next;
            Node* newnode = new Node{p->prev, x, p};
            p->prev->next = newnode;
            p->prev = newnode;            
        }
        this->size++;
    }
    else
        cout << "This isn't a Circular LinkedList !" << endl;
}

#endif