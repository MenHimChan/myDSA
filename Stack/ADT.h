// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-15
#ifndef ADT_H  
#define ADT_H
#include <iostream>
using namespace std;

// This is for excercise of Converting infix to postfix
struct Operator
{
    char symbol;
    int priority;
};
struct Operator Create(char sym);               // 给输入的运算符赋运算优先级
bool isOperator(char in);
///////////////////////////////////////////////////////////


template <class T>
class ArrayStack {
    private:
        int size;
        int top;
        T* arr;
    
    public:
        ArrayStack(int size);               // constructor
        ~ArrayStack();                      // deconstructor
        void Create();                      // Init the stack
        void Display();                     // Print the stack from top to bottom
        T peek(int pos);                    // Get the `pos` position value without moving top pointer, `pos` starting from 0
        bool pop(int& val);                 // pop the top elements and put it into val
        bool push(T x);                     // push x into the stack
        bool isFull() const;                // check the stack is full or not
        bool isEmpty() const;               // check the stack is empty or not
        int GetSize() const {return top+1;} // return the size of the stack
        int GetCap() const {return size;}   // return the capacity of the stack
};

template <class T>
void ArrayStack<T>::Create() {
    cout << "The capacity of stack is : " << this->size << endl;
    cout << "Input the total elements number of the stack, must less than capacity :";
    int cnt;
    cin >> cnt;
    if(cnt <= size) {
        for(int i = 0; i < cnt; i++) {
            cout << "push : ";
            T tmp;
            cin >> tmp;
            if(push(tmp)) {}
            else
                cout << "push value : " << tmp << "failed !!" << endl;
        }
    }
    else
        cout << "Input value must be smaller than the size :" << this->size << endl;
}

template <class T>
T ArrayStack<T>::peek(int pos) {
    int idx = top - pos;
    if(idx < 0) {
        cout << "Invalid `pos` !" << endl;
        return -1;
    }
    else
        return arr[idx];
} 

template <class T>
ArrayStack<T>::ArrayStack(int size) {
    this->size = size;
    this->top = -1;
    this->arr = new T[this->size];
}

template <class T>
ArrayStack<T>::~ArrayStack() {
    delete[] arr;
}

template <class T>
bool ArrayStack<T>::isFull() const {
    if(this->top >= this->size - 1) {
        return true;
    }
    return false;
}

template <class T>
bool ArrayStack<T>::isEmpty() const {
    if(this->top == -1)       // 栈空
        return true;
    return false;
}

template <class T>
bool ArrayStack<T>::push(T x) {
    if(isFull()) 
        return false;
    arr[++this->top] = x;
    return true;
}

template <class T>
bool ArrayStack<T>::pop(int& val) {
    if(isEmpty())
        return false;
    val = arr[this->top--];
    return true;
}

template <class T>
void ArrayStack<T>::Display() {
    cout << "Stack : [";
    for(int i = 0; i <= top; i++) {
        cout << arr[i];
        if(i != top)
            cout << " | ";
        else
            cout << " ";
    }
    cout << endl;
}

///////////////////////////////// Stack using LinkedList ////////////////////////////
template <class T>
class LinklistStack {
    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* top;
    public:
        LinklistStack() : top(nullptr) {}
        ~LinklistStack();
        bool isEmpty();
        bool isFull();                          // the stack is full when heap is full
        void Init();                            // Init the stack with input value
        T peek(int pos);                        // return the `pos` value 
        int GetSize();                          // return the size of stack
        bool push(T x);                         // push x into the stack
        bool pop(T& x);                         // pop the value into x
        void Display();                         // display the whole stack
};

template <class T>
LinklistStack<T>::~LinklistStack() {
    // delete all nodes 
    while(top) {        
        Node* tmp = top;
        top = top->next;
        delete tmp;
    }
}

template <class T>
bool LinklistStack<T>::isEmpty() {
    if(top == nullptr)
        return true;
    return false;
}

template <class T>
bool LinklistStack<T>::isFull() {
    Node* newnode = new Node;
    if(newnode == nullptr) 
        return true;
    return false;
}

template <class T>
int LinklistStack<T>::GetSize() {
    Node *p = top;
    int cnt = 0;
    for(; p != nullptr; p=p->next)
        cnt++;
    return cnt;
}

template <class T>
void LinklistStack<T>::Display() {
    cout << "=========== The stack is : ============" << endl;
    // 1. 找最大宽度
    int maxWidth = 0;
    for(Node* p = top; p != nullptr; p = p->next) {
        int len = to_string(p->data).length();
        if(len > maxWidth) maxWidth = len;
    }

    // 2. 居中打印
    for(Node* p = top; p != nullptr; p = p->next) {
        std::string s = to_string(p->data);
        int pad = maxWidth - s.length();
        int left = pad / 2;
        int right = pad - left;
        if(p == top)
            cout << "| " << std::string(left, ' ') 
                << s << std::string(right, ' ') << " |" << " <---top" << endl;
        else 
            cout << "| " << std::string(left, ' ') << s << std::string(right, ' ') << " |" << endl;
    }   
    cout << "=======================================" << endl;
}

template <class T>
bool LinklistStack<T>::push(T x) {
    if(!isFull()) {
        Node* newnode = new Node{x, top};
        top = newnode;
        return true;
    }
        return false;
}

template <class T>
bool LinklistStack<T>::pop(T& x) {
    if(!isEmpty()) {
        x = top->data;
        Node* tmp = top;
        top = top->next;
        delete tmp;
        return true;
    }
    return false;
}

template <class T>
void LinklistStack<T>::Init() {
    int nElems;
    cout << "Input the elements number you want to put into the stack : ";
    cin >> nElems;
    for(int i = 0; i < nElems; i++) {
        T tmp;
        cout << "Push : ";
        cin >> tmp;
        cout << "Success ? : " << push(tmp) << endl;
    }
}

template <class T>
T LinklistStack<T>::peek(int pos) {
    if(pos >= 0 && pos <= GetSize() - 1) {
        Node* p = top;
        while(pos--) p = p->next;
        return p->data;
    }
    cout << "Invalid `pos` input ! " << endl;
    return -1;
}

#endif