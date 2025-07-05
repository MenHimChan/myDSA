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
    int RTotalNodes(TreeNode* node);
    int RTotalDeg2Nodes(TreeNode* node);
    T RSum(TreeNode* node);
    int maxDepth(TreeNode* node);

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {destory(root);}
    void Create(T root_val);                                    // 层序创建
    int RTotalNodes() {return RTotalNodes(this->root);}         // 递归求总节点数
    int RTotalDeg2Nodes() {return RTotalDeg2Nodes(this->root);} // 递归法求度为2的节点
    int maxDepth() {return maxDepth(this->root);}               // 递归法求二叉树最大深度
    int ITotalNodes();                                          // 迭代求总节点数，层序法
    T RSum() {return RSum(this->root);}                         // 递归求整棵树总和
    void PrintPreOrder() {PrintPreOrder(this->root);}           // 递归前序遍历
    void PrintInOrder() {PrintInOrder(this->root);}             // 递归中序遍历
    void PrintPostOrder() {PrintPostOrder(this->root);}         // 递归后序遍历
    void PrintPreOrder_stk() {PrintPreOrder_stk(this->root);}   // 迭代后序遍历
    void PrintInOrder_stk() {PrintInOrder_stk(this->root);}     // 迭代中序遍历
    void PrintPostOrder_stk() {PrintPostOrder_stk(this->root);} // 迭代后序遍历
    void PrintLevelOrder();                                     // 层序遍历
    
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
    if(node == nullptr) return;
    cout << node->data << ' ';
    PrintPreOrder(node->lchild);
    PrintPreOrder(node->rchild);
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

// 迭代层序遍历获得总节点数
template <class T>
int BinaryTree<T>::ITotalNodes() {
    queue<TreeNode*> fifo;
    int cnt = 0;
    fifo.push(this->root);
    while (!fifo.empty()) {                 // 只要没有空队，就持续循环
        TreeNode* node = fifo.front();      // 访问一个节点
        cnt++;
        if(node->lchild != nullptr) 
            fifo.push(node->rchild);
        if(node->rchild != nullptr)
            fifo.push(node->rchild);
        fifo.pop();
    }
    return cnt;
}

// 实际上是后续遍历
template <class T>
int BinaryTree<T>::RTotalNodes(TreeNode* node) {
    if(node == nullptr) return 0;
    int x = RTotalNodes(node->lchild);
    int y = RTotalNodes(node->rchild);
    return x+y+1;                       // 左节点总和 + 右节点总和 + 本节点(1)
}

template <class T>
T BinaryTree<T>::RSum(TreeNode* node) {
    if(node == nullptr) return 0;
    T sum_l = RSum(node->lchild);
    T sum_r = RSum(node->rchild);
    return sum_l + sum_r + node->data;
}

// 将判断条件改成 node->lchild == nullptr && node->rchild == nullptr 就是求叶子节点个数
template <class T>
int BinaryTree<T>::RTotalDeg2Nodes(TreeNode* node) {
    if(node == nullptr) return 0;
    int x = RTotalDeg2Nodes(node->lchild);
    int y = RTotalDeg2Nodes(node->rchild);
    if(node->lchild != nullptr && node->rchild != nullptr)
        return x + y + 1;
    else
        return x + y;
}

template <class T>
int BinaryTree<T>::maxDepth(TreeNode* node) {
    if(node == nullptr) return 0;
    int x = maxDepth(node->lchild);
    int y = maxDepth(node->rchild);
    if(x > 1)
        return x + 1;
    else    
        return y + 1;
}

template <class T>
class BinarySearchTree {
private:
    struct TreeNode {
        TreeNode* lc;
        T data;
        TreeNode* rc;
    };
    TreeNode* root;
    void destroy(TreeNode* node);
    void PrintPreorder(TreeNode* node);
    void PrintInorder(TreeNode* node);
    TreeNode* RInsert(TreeNode* node, T key);
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {destroy(this->root);}
    void PrintPreorder() {PrintPreorder(this->root);}
    void PrintInorder() {PrintInorder(this->root);}
    TreeNode* Search(T key);
    T GetRootValue() {return root->data;}
    void Insert(T key);
    void RInsert(T key) {this->root = RInsert(this->root, key);}
    void Create();
    void Delete(T key);
};

template <class T>
void BinarySearchTree<T>::destroy(TreeNode* node) {
    if(node != nullptr) {
        destroy(node->lc);
        destroy(node->rc);
        delete node;
    }
}

template <class T>
void BinarySearchTree<T>::Insert(T key) {
    TreeNode* curr = this->root;
    TreeNode* prev = nullptr;
    TreeNode* newnode = nullptr;
    while(curr != nullptr) {
        if(curr->data == key)           // 不重复插入元素
            return;             
        else if(curr->data > key) {
            prev = curr;
            curr = curr->lc;
        }
        else {
            prev = curr;
            curr = curr->rc;
        }
    }
    newnode = new TreeNode{nullptr, key, nullptr};
    if(prev == nullptr) 
        this->root = newnode;
    else if(key > prev->data) 
        prev->rc = newnode;
    else
        prev->lc = newnode;
}

template <class T>
typename BinarySearchTree<T>::TreeNode* BinarySearchTree<T>::RInsert(TreeNode* node, T key) {
    if(node == nullptr) {
        // 新建节点
        node = new TreeNode{nullptr, key, nullptr};
        return node;
    }
    if(key < node->data)
        node->lc = RInsert(node->lc, key);
    else if(key > node->data)
        node->rc = RInsert(node->rc, key);
    // 如果key等于node->data，不插入重复节点
    return node;
}

template <class T>
void BinarySearchTree<T>::Create() {
    T x;
    cout << "Input the elements you wants, first one is the root value, enter `-1` to exit : ";
    cin >> x;
    while(x != -1) {
        Insert(x);
        cin >> x;
    }
}

template <class T>
void BinarySearchTree<T>::PrintPreorder(TreeNode* node) {
    if(node == nullptr) return;
    cout << node->data << ' ';
    PrintPreorder(node->lc);
    PrintPreorder(node->rc);
}

template <class T>
void BinarySearchTree<T>::PrintInorder(TreeNode* node) {
    if(node == nullptr) return;
    PrintInorder(node->lc);
    cout << node->data << ' ';
    PrintInorder(node->rc);
}

template <class T>
typename BinarySearchTree<T>::TreeNode* BinarySearchTree<T>::Search(T key) {
    TreeNode* curr = this->root;
    while(curr != nullptr) {
        if(curr->data == key)
            return curr;
        else if(curr->data > key) 
            curr = curr->lc;
        else
            curr = curr->rc;            
    }
    return nullptr;
}

template <class T>
void BinarySearchTree<T>::Delete(T key) {
    TreeNode* curr = root, *prev = nullptr;
    while(curr != nullptr) {
        if(curr->data == key) 
            break;
        else if(curr->data > key) {
            prev = curr;
            curr = curr->lc;
        }
        else {
            prev = curr;
            curr = curr->rc;
        }
    }
    if(curr == nullptr) return;             // 查找失败

    // Delete Leaf node
    if(curr->lc == nullptr && curr->rc == nullptr) {
        if(prev->lc == curr)
            prev->lc = nullptr;        
        else 
            prev->rc = nullptr;
        delete curr;
    }

    // Delete Deg(node) = 1 Node
    else if((curr->lc != nullptr && curr->rc == nullptr) || 
            (curr->lc == nullptr && curr->rc != nullptr)) {
        // the only child of curr is left child
        if(curr->lc != nullptr) {
            if(prev->rc == curr)
                prev->rc = curr->lc;
            else
                prev->lc = curr->lc;
            delete curr;
        }
        // the only child of curr is right child
        else {
            if(prev->rc == curr)
                prev->rc = curr->rc;
            else
                prev->lc = curr->rc;
        }
    }
    // Delete Deg(node) = 2 Node
    else {
        // 找前驱
        TreeNode* p = curr->lc;
        TreeNode* pPrev = curr;         // 转移到左子树
        while(p->rc != nullptr) {       // 转移到左子树的最右边节点，也就是左子树最大值
            pPrev = p;
            p = p->rc;
        }
        curr->data = p->data;           // 用前驱值覆盖
        // 删除前驱节点p（p最多只有左孩子）
        if(pPrev->rc == p)
            pPrev->rc = p->lc;
        else
            pPrev->lc = p->lc;
        delete p;
    }
}

template <class T>
class AVL {
private:
    struct AVLNode {
        AVLNode* lc;
        T data;
        AVLNode* rc;
        int height;
    };
    AVLNode* root;
    void destory(AVLNode* node);
    int BalanceFactor(AVLNode* node);
    AVLNode* RInsert(AVLNode* node, T key);
    void LLRotation(AVLNode*& node);
    void RRRotation(AVLNode*& node);
    void LRRotation(AVLNode*& node);
    void RLRotation(AVLNode*& node);
    void PrintInorder(AVLNode* node);
public:
    AVL();
    ~AVL();
    void RInsert(T key) {this->root = RInsert(root, key);}
    void Create();
    void PrintInorder() {PrintInorder(this->root);}
    void PrintRootAddr() {cout << "root addr is : " << this->root << endl;}
    int GetHeight(AVLNode* node);
    int GetAVLHeight() {return GetHeight(this->root);}
};

template <class T>
int AVL<T>::GetHeight(AVLNode* node) {
    if(node == nullptr) return -1;
    return max(GetHeight(node->rc), GetHeight(node->lc)) + 1;
}
 
template <class T>
void AVL<T>::PrintInorder(AVLNode* node) {
    if(node == nullptr) {
        return;
    }
    PrintInorder(node->lc);
    cout << node->data << ' ';
    PrintInorder(node->rc);
}

// RL Rotation
//         A <- node                     C
//        / \                         /     \  
//      Al   B      ==>             A       B
//          / \                    / \     /  \  
//        C   Br                  Al  Cl  Cr  Br
//       / \
//     Cl  Cr
template <class T>
void AVL<T>::RLRotation(AVLNode*& node) {
    LLRotation(node->rc); // 先对node->rc做LL旋转
    RRRotation(node);     // 再对node做RR旋转
}

// LR Rotation
//         A <- node                     C
//        / \                         /     \  
//       B   Ar      ==>             B       A
//      / \                         / \     /  \  
//    Bl   C                       Bl  Cl  Cr   Ar
//        / \
//       Cl  Cr
template <class T>
void AVL<T>::LRRotation(AVLNode*& node) {
    RRRotation(node->lc); // 先对node->lc做RR旋转
    LLRotation(node);     // 再对node做LL旋转
}

// RR Rotation
// A B Bl needs to be operator
//         A <- node                     B
//        / \                         /     \  
//      Al   B                       A       C
//          / \        ==>          /  \    / \  
//        Bl   C                   Al  Bl  Cl  Cr
//            / \
//           Cl  Cr
template <class T>
void AVL<T>::RRRotation(AVLNode*& node) {
    AVLNode* B = node->rc;
    AVLNode* Bl = B->lc;
    // perform rotation
    B->lc = node;               // A(node)成为B的左子节点
    node->rc = Bl;              // B的左子节点成为A(node)的右子节点
    // renew height
    node->height = max(GetHeight(node->rc), GetHeight(node->lc)) + 1;
    B->height = max(GetHeight(B->rc), GetHeight(B->lc)) + 1;
    // let B become root
    node = B;
}

// LL Rotation
//         A <- node                     B
//        / \                         /    \  
//       B   Ar                      C       A
//      / \         ==>             / \     / \  
//     C   Br                      Cl  Cr  Br  Ar
//    / \
//   Cl  Cr
template <class T>
void AVL<T>::LLRotation(AVLNode*& node) {
    AVLNode* B = node->lc;
    AVLNode* Br = B->rc;
    // rotation
    B->rc = node;                  // A(node)成为B的右子节点
    node->lc = Br;              // B的右子节点成为A的左子节点
    // renew height
    node->height = max(GetHeight(node->lc), GetHeight(node->rc)) + 1;
    B->height = max(GetHeight(B->lc), GetHeight(B->rc)) + 1;
    // Let B become new root
    node = B;
}

// 插入一个节点之后，检查根节点的bf，如果失衡，则根据对应类型旋转树。
template <class T>
typename AVL<T>::AVLNode* AVL<T>::RInsert(AVLNode* node, T key) {
    // 标准BST插入
    if(node == nullptr) {
        node = new AVLNode{nullptr, key, nullptr, 0};
        return node;
    }
    if(key > node->data)
        node->rc = RInsert(node->rc, key);
    else if(key < node->data)
        node->lc = RInsert(node->lc, key);
    else                                    // 重复值，不进行插入
        return node;
    
    // renew height of root
    node->height = GetHeight(node);
    
    // LL Rotation
    if(BalanceFactor(node) == 2 && BalanceFactor(node->lc) >= 0)
        LLRotation(node);
    // LR Rotation
    else if(BalanceFactor(node) == 2 && BalanceFactor(node->lc) < 0) 
        LRRotation(node);
    // RR Rotation
    else if(BalanceFactor(node) == -2 && BalanceFactor(node->rc) <= 0)
        RRRotation(node);
    // RL Rotation
    else if(BalanceFactor(node) == -2 && BalanceFactor(node->rc) > 0) 
        RLRotation(node);
    
    return node;
}

// berf: 计算传入节点的平衡因子
// bf: 空节点：   return 0
//     叶子节点： return 0
template <class T>
int AVL<T>::BalanceFactor(AVLNode* node) {
    return node ? GetHeight(node->lc) - GetHeight(node->rc) : 0;
}

template <class T>
void AVL<T>::destory(AVLNode* node) {
    if(node) {
        destory(node->lc);
        destory(node->rc);
        delete node;
    }
}

template <class T>
AVL<T>::AVL() {
    this->root = nullptr;
}

template <class T>
AVL<T>::~AVL() {
    destory(this->root);
}

template <class T>
void AVL<T>::Create() {
    T x;
    cout << "Input the elements you want to insert into the AVL tree, enter `-1` to exit: ";
    cin >> x;
    while(x != -1) {
        RInsert(x); // 调用插入函数
        cin >> x;
    }
}


#endif