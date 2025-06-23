// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-18
#ifndef ADT_H  
#define ADT_H
#include <iostream>
using namespace std;


template <class T>
class ArrayQueue {
    private:
        int size;               // capacity of the Queue
        int front;              // front index, the first elements of this queue can be access by (front + 1)
        int rear;               // rear index, access this index it will return the last elements of this queue
        T* arr;                 // the physic container
    public:
        ArrayQueue(int size);
        ~ArrayQueue();
        bool Enqueue(T x);                               // Enqueue x into the queue, return true if succeed
        bool Dequeue(T& x);                              // Dequeue the first elements outside the queue, put the value in x, return true if succeed
        bool isFull();
        bool isEmpty(); 
        void Display() const;  
        int GetFront() const {return front;}
        int GetRear() const {return rear;}                               
};

template <class T>
ArrayQueue<T>::ArrayQueue(int size) {
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->arr = new T[size];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] arr;
}

template <class T>
bool ArrayQueue<T>::Enqueue(T x) {
    if(isFull())
        return false;
    arr[++rear] = x;
    return true;
}

template <class T>
bool ArrayQueue<T>::Dequeue(T& x) {
    if(isEmpty()) 
        return false;
    x = arr[++front];
    return true;
}

template <class T>
bool ArrayQueue<T>::isFull() {
    if(rear == size-1)
        return true;
    return false;
}

template <class T>
bool ArrayQueue<T>::isEmpty() {
    if(front == rear)
        return true;
    return false;
}

template <class T>
void ArrayQueue<T>::Display() const {
    cout << "[FRONT] :";
    for(int i = front+1; i <= rear; i++) {
        if(i == rear)
            cout << arr[i] << "[REAR]";
        else
            cout << arr[i] << ' ';
    }
    cout << endl;
}

template <class T>
class ArrayCircularQueue {
    private:
        int size;               // capacity of the Queue
        int front;              // front index, the first elements of this queue can be access by (front + 1)
        int rear;               // rear index, access this index it will return the last elements of this queue
        T* arr;                 // the physic container
    public:
        ArrayCircularQueue(int size);
        ~ArrayCircularQueue();
        bool Enqueue(T x);                               // Enqueue x into the queue, return true if succeed
        bool Dequeue(T& x);                              // Dequeue the first elements outside the queue, put the value in x, return true if succeed
        bool isFull();
        bool isEmpty(); 
        void Display() const;  
        int GetFront() const {return front;}
        int GetRear() const {return rear;}    
        int GetSize() const {return size;}
        int TotalElems();                          
};

template <class T>
ArrayCircularQueue<T>::ArrayCircularQueue(int size) {
    this->size = size;
    this->front = 0;
    this->rear = 0;
    this->arr = new T[size];
}

template <class T>
ArrayCircularQueue<T>::~ArrayCircularQueue() {
    delete[] arr;
}

template <class T>
bool ArrayCircularQueue<T>::Enqueue(T x) {
    if(isFull())
        return false;
    rear = (rear + 1) % size;
    arr[rear] = x;
    return true;
}

template <class T>
bool ArrayCircularQueue<T>::Dequeue(T& x) {
    if(isEmpty()) 
        return false;
    x = arr[(front + 1) % size];
    front = (front + 1) % size;
    return true;
}

template <class T>
bool ArrayCircularQueue<T>::isFull() {
    if(front == (rear + 1)%size)
        return true;
    return false;
}

template <class T>
bool ArrayCircularQueue<T>::isEmpty() {
    if(front == rear)
        return true;
    return false;
}

template <class T>
void ArrayCircularQueue<T>::Display() const {
    cout << "[FRONT] : ";
    for(int i = (front + 1) % size; i != rear + 1; i = (i + 1) % size) {
        if(i == rear)
            cout << arr[i] << " [REAR]";
        else
            cout << arr[i] << ' ';
    }
    cout << endl;
}

template <class T>
int ArrayCircularQueue<T>::TotalElems() {
    return rear - front + size;
}

template <class T>
class LinkedListQueue {
    private:
        struct Node
        {
            T data;
            Node* next;
        };
        Node* front;
        Node* rear;
    public:
        LinkedListQueue();
        ~LinkedListQueue();
        bool isFull();
        bool isEmpty();
        bool Enqueue(T x);
        bool Dequeue(T& x);
        void Display();
        int TotalElems() const;
        T GetAt(int pos) const;
};

template <class T>
int LinkedListQueue<T>::TotalElems() const {
    int ret = 0;
    for(Node *p = front; p != nullptr; p=p->next)
        ret++;
    return ret;
}

template <class T>
T LinkedListQueue<T>::GetAt(int pos) const {
    if(pos >= 0 && pos <= TotalElems() - 1) {
        Node* p = front;
        while(pos--) p=p->next;
        return p->data;
    }
    else
        cout << "Invalid `pos` input ! " << endl;
        return -100000;
}

template <class T>
LinkedListQueue<T>::LinkedListQueue() {
    this->front = nullptr;
    this->rear = nullptr;
}

template <class T>
LinkedListQueue<T>::~LinkedListQueue() {
    Node* p = front;
    while(p) {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
}

template <class T>
bool LinkedListQueue<T>::isFull() {
    Node* newnode = new Node;
    if(newnode == nullptr)
        return true;
    return false;
}

template <class T>
bool LinkedListQueue<T>::isEmpty() {
    if (front == nullptr) 
        return true;
    return false;
}

template <class T>
bool LinkedListQueue<T>::Enqueue(T x) {
    Node* newnode = new Node{x, nullptr};
    if (newnode == nullptr) return false;
    if(!isFull()) {
        if(front == nullptr && rear == nullptr) {
            front = newnode;
            rear  = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
        return true;
    }
    return false;
}

template <class T>
bool LinkedListQueue<T>::Dequeue(T& x) {
    if(!isEmpty()) {
        Node* tmp = front;
        x = tmp->data;
        front = front->next;
        delete tmp;
        return true;
    }
    return false;
}

template <class T>
void LinkedListQueue<T>::Display() {
    for(Node* p = front; p != nullptr; p=p->next) {
        cout << p->data << ' ';
    }
    cout << endl;
}
#endif