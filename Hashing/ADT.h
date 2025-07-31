// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-28

#ifndef __ADT__H__
#define __ADT__H__

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 枚举成员本质是整型常量。
enum AntiHashCollusionType {
    Chaining,
    LinearProbe,
};

template <class T>
class HashTable {
private:
    struct Node{
        T data;
        Node* next;
    };
    double load_factor = 0.75;              // 装载因子
    int size;                               // 哈希表大小，由key_len / load_factor 确定
    int prime;                              // 保存 <= size的最大质数，作为模数
    int nElems;                             // 保存哈希表中所存元素的个数                   
    AntiHashCollusionType AntiColluType;    // 防止冲突的类型
    vector<Node*> vec_opening;              // 适用于opening hashing，即chaining
    vector<T> vec_closing;                  // 适用于closing hashing
    int hash_fun(const T& key) const;       // 哈希函数，输入key求得该key在哈希表中的下表
    int GetMaxPrimeLE(int num) const;       // 求小于 <= key_len的最大质数

public:
    HashTable(int keysnum, AntiHashCollusionType antitype) : 
        size((int)(ceil(keysnum / load_factor))), 
        prime(GetMaxPrimeLE(size)), 
        AntiColluType(antitype),
        nElems(0) {
            if(AntiColluType == Chaining) 
                vec_opening.resize(size);
        }
    ~HashTable();
    void Create(T* arr, int len);
    void priv(void);
    void Display(void);
    T Search(T key);
    void Insert(T key);
    void ResizeAndReHash();
};

template <class T>
void HashTable<T>::ResizeAndReHash() {
    int new_size = size*2;
    int new_prime = GetMaxPrimeLE(new_size);
    vector<Node*> new_vec_opening(new_size, nullptr);

    // 重插所有元素到新容器中
    for(auto head : vec_opening) {
        Node* p = head;           // head
        while(p) {
            int idx = p->data % new_prime;
            Node* newnode = new Node{p->data, nullptr};
            newnode->next = new_vec_opening[idx];
            new_vec_opening[idx] = newnode;
            p = p->next;
        }
    }

    // 释放旧桶的所有节点
    for(auto& head : vec_opening) {
        Node* p = head;
        while(p) {
            Node* tmp = p->next;
            delete p;
            p = tmp;
        }
    }

    // 用 new_vec_opening 变量覆盖 vec_opening
    this->vec_opening = move(new_vec_opening);
    this->size = new_size;
    this->prime = new_prime;
}

template <class T>
void HashTable<T>::Insert(T key) {
    if(AntiColluType == Chaining) {
        if((double)nElems / size > load_factor) ResizeAndReHash();
        int idx = hash_fun(key);
        // 头插法
        Node* newnode = new Node{key, nullptr};
        newnode->next = vec_opening[idx];
        vec_opening[idx] = newnode;
        this->nElems++;
    }
}

template <class T>
T HashTable<T>::Search(T key) {
    if(AntiColluType == Chaining) {
        int idx = hash_fun(key);
        Node* p = vec_opening[idx];
        while(p) {
            if(p->data == key) return p->data;
            p = p->next;
        }
        cout << "Key not found in the hash table !" << endl;
        return T();
    }
    throw std::logic_error("idx only supports Chaining mode");
    return T();
}

template <class T>
void HashTable<T>::Display(void) {
    if(AntiColluType == Chaining) {
        cout << "------------ Printing the Hashtable ------------" << endl;
        for(int i = 0; i < size; i++) {
            cout << "HashTable" << "[ " <<  i << " ]" << ':' << " ";
            Node* p = vec_opening[i];
            if(!p)  cout << "nullptr";
            else {
                while(p != nullptr) {
                    cout << p->data << " -> ";
                    p = p->next;
                }
                cout << "nullptr";
            }
            cout << endl;
        }
        cout << "------------ End Printing ------------" << endl;
    }
}

template <class T>
HashTable<T>::~HashTable() {
    // 只需释放链地址法分配的节点
    if (AntiColluType == Chaining) {
        for (auto& head : vec_opening) {
            Node* p = head;
            while (p) {
                Node* tmp = p->next;
                delete p;
                p = tmp;
            }
        }
    }
}

template <class T>
void HashTable<T>::priv(void) {
    cout << "------------ Printing private variabe ------------" << endl;
    cout << "this->size : " << this->size << endl;
    cout << "this->load_factor : " << this->load_factor << endl;
    cout << "this->prime : " << this->prime << endl;
    cout << "this->AntiColluType : " << this->AntiColluType << endl;
    cout << "this->nElems : " << this->nElems << endl;
    cout << "------------ End Printing------------" << endl;
}

template <class T>
void HashTable<T>::Create(T* arr, int len) {
    if(AntiColluType == Chaining) {
        for(int i = 0; i < len; i++) {
            int idx = hash_fun(arr[i]);
            Node* newnode = new Node{arr[i], nullptr};
            newnode->next = vec_opening[idx];
            vec_opening[idx] = newnode;
        }
        this->nElems = len;
    }
}

template <class T>
int HashTable<T>::GetMaxPrimeLE(int num) const{
    if(num < 2) return -1;
    auto isPrime = [](int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; ++i)
            if(n % i == 0) return false;
        return true;
    };
    for(int i = num; i >= 2; --i) {
        if(isPrime(i)) return i;
    }
    return -1;
}

template <class T>
int HashTable<T>::hash_fun(const T& key) const {
    return key % prime;
}



#endif