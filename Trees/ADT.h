// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-22

#ifndef ADT_H
#define ADT_H
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class BinaryTree {
private:
    struct TreeNode {
        TreeNode* lchild;
        T data;
        TreeNode* rchild;
    };
    TreeNode* root;
    void destory(TreeNode* node);
    void PrintPreOrder(TreeNode* node);
    void PrintInOrder(TreeNode* node);
    void PrintPostOrder(TreeNode* node);
    void PrintPreOrder_stk(TreeNode* node);
    void PrintInOrder_stk(TreeNode* node);
    void PrintPostOrder_stk(TreeNode* node);

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {destory(root);}
    void Create(T root_val);
    void PrintPreOrder() {PrintPreOrder(this->root);}
    void PrintInOrder() {PrintInOrder(this->root);}
    void PrintPostOrder() {PrintPostOrder(this->root);}
    void PrintPreOrder_stk() {PrintPreOrder_stk(this->root);}
    void PrintInOrder_stk() {PrintInOrder_stk(this->root);}
    void PrintPostOrder_stk() {PrintPostOrder_stk(this->root);}
    void PrintLevelOrder();
};

template <class T>
void BinaryTree<T>::destory(TreeNode* node) {
    if(node) {
        destory(node->lchild);
        destory(node->rchild);
        delete node;
    }
}

template <class T>
void BinaryTree<T>::Create(T root_val) {
    TreeNode *p, *tmp;
    T x;
    queue<TreeNode*> fifo;
    this->root = new TreeNode{nullptr, root_val, nullptr};
    fifo.push(root);
    cout << "The elements will be filled from left to right, Input `-1` if you want this child node left vacant : " << endl;
    while (!fifo.empty()) {
        p = fifo.front();
        fifo.pop();
        cout << "Input Left Child Node of now node, whose value is " << p->data << " : ";
        cin >> x;
        if(x != -1) {
            tmp = new TreeNode{nullptr, x, nullptr};
            p->lchild = tmp;
            fifo.push(tmp);
        }
        cout << "Input Right Child Node of now node, whose value is " << p->data << " : ";
        cin >> x;
        if(x != -1) {
            tmp = new TreeNode{nullptr, x, nullptr};
            p->rchild = tmp;
            fifo.push(tmp);
        }
    }
}

template <class T>
void BinaryTree<T>::PrintPreOrder(TreeNode* node) {
    if(node != nullptr) {
        cout << node->data << " ";
        PrintPreOrder(node->lchild);
        PrintPreOrder(node->rchild);
    }
}

template <class T>
void BinaryTree<T>::PrintInOrder(TreeNode* node) {
    if(node != nullptr) {
        PrintInOrder(node->lchild);
        cout << node->data << " ";
        PrintInOrder(node->rchild);
    }
}

template <class T>
void BinaryTree<T>::PrintPostOrder(TreeNode* node) {
    if(node != nullptr) {
        PrintPostOrder(node->lchild);
        PrintPostOrder(node->rchild);
        cout << node->data << " ";
    }
}

// using iteration method to do the Preorder traversal
template <class T>
void BinaryTree<T>::PrintPreOrder_stk(TreeNode* node) {
    stack<TreeNode*> lifo;
    while (node != nullptr || !lifo.empty()) {
        if(node != nullptr) {
            cout << node->data << ' ';
            lifo.push(node);
            node = node->lchild;
        }
        else {
            node = lifo.top();
            lifo.pop();
            node = node->rchild;
        }
    }
    cout << endl;
}

template <class T>
void BinaryTree<T>::PrintInOrder_stk(TreeNode* node) {
    stack<TreeNode*> lifo;
    while (node != nullptr || !lifo.empty()) {
        if(node != nullptr) {
            lifo.push(node);
            node = node->lchild;
        }
        else {
            node = lifo.top();
            lifo.pop();
            cout << node->data << ' ';
            node = node->rchild;
        }
    }
    cout << endl;
}

template <class T>
void BinaryTree<T>::PrintPostOrder_stk(TreeNode* node) {
    stack<TreeNode*> lifo;
    TreeNode* lastVisit = nullptr;
    while (node != nullptr || !lifo.empty()) {
        if(node != nullptr) {
            lifo.push(node);
            node = node->lchild;
        }
        else {
            TreeNode* top = lifo.top();         // 取栈顶元素
            if(top->rchild != nullptr && lastVisit != top->rchild) // 右节点没访问过且右节点非空
                node = top->rchild;                                // 访问右边节点
            else {
                cout << top->data << ' ';       // 可以访问本节点
                lastVisit = top;
                lifo.pop();
            }
        }
    }
    cout << endl;
}

template <class T>
void BinaryTree<T>::PrintLevelOrder() {
    queue<TreeNode*> fifo;
    fifo.push(this->root);
    while (!fifo.empty()) {
        TreeNode* p = fifo.front();
        cout << p->data << ' ';
        if(p->lchild != nullptr) 
            fifo.push(p->lchild);
        if(p->rchild != nullptr) 
            fifo.push(p->rchild);
        fifo.pop();
    }
    cout << endl;
}


#endif