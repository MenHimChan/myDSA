// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-28

#ifndef __ADT__H__
#define __ADT__H__

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;


// 枚举成员本质是整型常量。
enum AntiHashCollusionType {
    Chaining,                           // 链地址法
    LinearProbe,                        // 线性探测法
    QuadraticProbe,                     // 二次探测法
};

template <class T>
class HashTable {
private:
    const T EMPTY = std::numeric_limits<T>::min();   // 空值
    const T DELETED = std::numeric_limits<T>::max(); // 删除值
    // 链地址法的结点结构体
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
    int GetMin4k3PrimeGE(int num) const;    // 求大于等于num的第一个4k+3质数

public:
    HashTable(int keysnum, AntiHashCollusionType antitype) : size((int)(ceil(keysnum / load_factor))), prime(GetMaxPrimeLE(size)), AntiColluType(antitype), nElems(0) {
        if(AntiColluType == Chaining) 
            vec_opening.resize(size);
        else if(AntiColluType == LinearProbe)
            vec_closing.resize(size, EMPTY);
        else if(AntiColluType == QuadraticProbe) {
            load_factor = 0.5;                      // 二次探测法装填因子
            size = GetMin4k3PrimeGE((int)(ceil(keysnum / load_factor)));
            prime = GetMaxPrimeLE(size);
            vec_closing.resize(size, EMPTY);
        }
    }
    ~HashTable();
    void Create(T* arr, int len);
    void priv(void);
    void Display(void);
    T Search(T key);
    void Insert(T key);
    void Delete(T key);
    void ResizeAndReHash();
};

template <class T>
int HashTable<T>::GetMin4k3PrimeGE(int num) const {
    auto isPrime = [](int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; ++i)
            if(n % i == 0) return false;
        return true;
    };
    int candidate = num;
    while (true) {
        if (candidate % 4 == 3 && isPrime(candidate)) {
            return candidate;
        }
        candidate++;
    }
}

template <class T>
void HashTable<T>::Delete(T key) {
    // Chaining method
    if(AntiColluType == Chaining) {
        // 算哈希地址
        int idx = hash_fun(key);
        // 删链表的结点
        Node* curr = vec_opening[idx], *prev = nullptr;
        if(curr == nullptr) {
            cout << "Key : " << key << "is not exist in the hashtable ! " << endl;
            return;
        }
        else {
            while(curr != nullptr) {
                if(curr->data == key) {
                    if(prev == nullptr) {                   // prev 没动说明key在head被找到
                        vec_opening[idx] = curr->next;
                        delete curr;
                        nElems--;
                        return;     
                    }
                    else {
                        prev->next = curr->next;            // 除head外其他位置
                        delete curr;
                        nElems--;
                        return;
                    }
                }
                prev = curr;
                curr = curr->next;
            }
            // 没查找到
            cout << "Key : " << key << "is not exist in the hashtable !" << endl;
        }
    }
    // LinearProbing method
    else if(AntiColluType == LinearProbe) {
        // 算哈希地址
        int idx = hash_fun(key);
        if(vec_closing[idx] == key) {                // 直接在当前位置找到
            vec_closing[idx] = DELETED;              // 置为删除值
            nElems--;
            return;
        }
        else {
            int i = idx + 1;
            while(vec_closing[i] != EMPTY) {    
                if(i == size) i = 0;                 // 环形探测
                if(vec_closing[i] == key) {          // 在i位置找到
                    vec_closing[i] = DELETED;        // 置为删除值
                    nElems--;
                    return;
                }
                i++;
            }
            cout << "Key : " << key << "is not exist in the hashtable !" << endl; // 没查找到
        }
    }
    else if(AntiColluType == QuadraticProbe) {
        // Derive hash address
        int idx = hash_fun(key);
        // if found at idx
        if(vec_closing[idx] == key) {
            vec_closing[idx] = DELETED;
            nElems--;
            return;
        }
        else {
            for(int sign=1, base=1, offset=1, idx_offset=(idx+offset+size) % size; 
                vec_closing[idx_offset] != EMPTY;                                   // 遇到empty就停止，说明没查到
                sign*=-1, offset=base*base*sign, idx_offset=(idx+offset+size) % size) {
                if(vec_closing[idx_offset] == key) {
                    vec_closing[idx_offset] = DELETED;
                    nElems--;
                    return;
                }
                if(offset < 0) base++;
            }
            cout << "Key : " << key << " is not exist in the hashtable !" << endl; // 没查找到
        }
    }
}

template <class T>
void HashTable<T>::ResizeAndReHash() {
    if(AntiColluType == Chaining) {
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

    else if(AntiColluType == LinearProbe) {
        int new_size = size * 2;
        int new_prime = GetMaxPrimeLE(new_size);        // 根据new_size计算出的最大质数
        vector<T> new_vec_closing(new_size, EMPTY);     // 新哈希表
        for(int i = 0; i < size; ++i) {
            if(vec_closing[i] != EMPTY && vec_closing[i] != DELETED) {    // 只处理原hashtable的非空位置
                int idx = vec_closing[i] % new_prime;           
                // 如果新hashtable当前位置为空，直接填入
                if(new_vec_closing[idx] == EMPTY) 
                    new_vec_closing[idx] = vec_closing[i];
                else {  // 如果当前位置非空，线性探测
                    int j = idx + 1;
                    while(new_vec_closing[j] != EMPTY) {
                        j++;
                        if(j == new_size) j = 0; // 环形探测
                    }
                    new_vec_closing[j] = vec_closing[i];
                }
            }
        }
        // 用 new_vec_closing 变量覆盖 vec_closing
        this->vec_closing = move(new_vec_closing);
        this->size = new_size;
        this->prime = new_prime;
    }

    else if(AntiColluType == QuadraticProbe) {
        int new_size = GetMin4k3PrimeGE(size * 2);          // 新表长是大于size*2 的第一个4k+3质数
        int new_prime = GetMaxPrimeLE(new_size);            // 模值是小于等于表长的最大质数
        vector<T> new_vec_closing(new_size, EMPTY);
        for(int i = 0; i < size; i++) {
            if(vec_closing[i] != EMPTY && vec_closing[i] != DELETED) {      // 只存有数值的位置
                int idx = vec_closing[i] % new_prime;                       // 先求哈希地址
                if(new_vec_closing[idx] == EMPTY) new_vec_closing[idx] = vec_closing[i];    // 如果哈希地址下没存任何东西，直接放进去
                else {
                    int sign=1, base=1, offset=base*base*sign, idx_offset=(idx+offset+size)%size;   // 找到第一个empty的位置
                    while(new_vec_closing[idx_offset] != EMPTY) {
                        if(offset < 0) base++;
                        sign*=-1;
                        offset = base*base*sign;
                        idx_offset=(idx+offset+size) % size;
                    }
                    new_vec_closing[idx_offset] = vec_closing[i];
                }
            }
        }
        this->vec_closing = move(new_vec_closing);
        this->size = new_size;
        this->prime = new_prime;
    }
}

template <class T>
void HashTable<T>::Insert(T key) {
    if(AntiColluType == Chaining) {
        if((double)(nElems + 1) / size > load_factor) ResizeAndReHash();
        int idx = hash_fun(key);
        // 头插法
        Node* newnode = new Node{key, nullptr};
        newnode->next = vec_opening[idx];
        vec_opening[idx] = newnode;
        this->nElems++;
    }
    else if(AntiColluType == LinearProbe) {
        if((double)(nElems + 1) / size > load_factor) ResizeAndReHash();
        int idx = hash_fun(key);
        if(vec_closing[idx] == EMPTY || vec_closing[idx] == DELETED) vec_closing[idx] = key;    // 当前位置为空标记或者删除标记
        else {                                                       // 当前位置非空
            int j = idx + 1;
            // 寻找idx之后的第一个空位置或者删除位置
            while(vec_closing[j] != EMPTY && vec_closing[j] != DELETED) { // 线性探测
                if(j == size) j = 0;                                      // 环形探测
                j++;
            }
            vec_closing[j] = key;
        }
        this->nElems++;
    }
    else if(AntiColluType == QuadraticProbe) {
        if((double)(nElems + 1) / size > load_factor) ResizeAndReHash();
        int idx = hash_fun(key);
        if(vec_closing[idx] == EMPTY || vec_closing[idx] == DELETED) vec_closing[idx] = key;
        else {
            int sign=1, base=1, offset=base*base*sign, idx_offset=(idx+offset+size) % size;
            while(vec_closing[idx_offset] != EMPTY && vec_closing[idx_offset] != DELETED) {
                if(offset < 0) base++;
                sign *= -1;
                offset = base*base*sign;
                idx_offset = (idx+offset+size) % size;
            }
            vec_closing[idx_offset] = key;
        }
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
        cout << "Key " << key << " not found in the hash table, return : ";
        return T();
    }
    else if(AntiColluType == LinearProbe) {
        int idx = hash_fun(key);
        if(vec_closing[idx] == key) return key;         // 直接在当前位置找到
        else {              
            int i = idx + 1;
            while(vec_closing[i] != EMPTY) {
                if(i == size) i = 0;                     // 环形探测
                if(key == vec_closing[i]) return key;
                i++;
            }
            cout << "Key " << key << " not found in the hash table, return : ";
            return T();
        }
    }
    else if(AntiColluType == QuadraticProbe) {
        // derive hash address
        int idx = hash_fun(key);
        if(vec_closing[idx] == key) return key;
        else {
            for(int sign=1, base=1, offset=base*base*sign, idx_offset=(idx+offset+size) % size;
                vec_closing[idx_offset] != EMPTY;
                sign*=-1, offset=base*base*sign, idx_offset=(idx+offset+size) % size) {
                if(vec_closing[idx_offset] == key) return key;
                if(offset < 0) base++;
            }
            cout << "Key " << key << " not found in the hash table, return : ";
            return T();
        }
    }
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
    else if(AntiColluType == LinearProbe) {
        cout << "------------ Printing the Hashtable ------------" << endl;
        for(int i = 0; i < size; i++) {
            cout << "HashTable" << "[ " <<  i << " ]" << ':' << " ";
            if(vec_closing[i] == EMPTY) cout << "Empty";
            else if(vec_closing[i] == DELETED) cout << "Deleted";
            else cout << vec_closing[i];
            cout << endl;
        }
        cout << "------------ End Printing ------------" << endl;
    }
    else if(AntiColluType == QuadraticProbe) {
        cout << "------------ Printing the Hashtable ------------" << endl; 
        for(int i = 0; i < size; i++) {
            cout << "HashTable" << "[ " <<  i << " ]" << ':' << " ";
            if(vec_closing[i] == EMPTY) cout << "Empty";
            else if(vec_closing[i] == DELETED) cout << "Deleted";
            else cout << vec_closing[i];
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
    else if(AntiColluType == LinearProbe)  return;
    else if(AntiColluType == QuadraticProbe) return; 
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
    else if(AntiColluType == LinearProbe) {
        for(int i = 0; i < len; i++) {
            int idx = hash_fun(arr[i]);
            if(vec_closing[idx] == numeric_limits<T>::min()) vec_closing[idx] = arr[i]; // 当前位置为空，直接填入
            else {      // 当前位置非空
                int j = idx + 1;
                while(vec_closing[j] != numeric_limits<T>::min()) {
                    j++;
                    if(j == size) j = 0;
                }
                vec_closing[j] = arr[i];
            }
        }
        this->nElems = len;
    }
    else if(AntiColluType == QuadraticProbe) {
        for(int i = 0; i < len; i++) {
            int idx = hash_fun(arr[i]);
            if(vec_closing[idx] == EMPTY) vec_closing[idx] = arr[i];      // 当前位置为空，直接填入
            else {
                // int exp = 2;                                           // 二次探测的指数
                for(int sign=1, base=1; ;sign*=-1) {
                    int offset = base * base * sign;
                    int idx_offset = (idx+offset+size) % size;            // +size是为了处理负数索引
                    if(vec_closing[idx_offset] == EMPTY) {
                        vec_closing[idx_offset] = arr[i];
                        break;
                    }
                    if(offset < 0) base++;
                }
            }
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