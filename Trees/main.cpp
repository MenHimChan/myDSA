// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-22

#include "ADT.h"

int main() {

    /////////////////////////////// Binary Trees //////////////////////////
    // testing create
    // BinaryTree<int> bt;
    // bt.Create(5);
    // bt.PrintPreOrder();
    // cout << endl;

    // testing Traversal using recursion
    // BinaryTree<int> bt;
    // bt.Create(5);
    // bt.PrintInOrder();
    // cout << endl;
    // bt.PrintPostOrder();
    // cout << endl;

    // testing Traversal using iterative
    // test case: 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    //     8
    //    / \
    //   3    5
    //  / \   / \
    // 4   9  7  2
    // BinaryTree<int> bt;
    // bt.Create(8);
    // bt.PrintPreOrder_stk();
    // bt.PrintInOrder_stk();
    // bt.PrintPostOrder_stk();
    // bt.PrintLevelOrder();

    // testing TotalNodes() 
    // test case: 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTree<int> bt;
    // bt.Create(8);
    // cout << "----------------" << endl;
    // cout << bt.RTotalNodes() << endl;           // 递归实现
    // cout << bt.ITotalNodes() << endl;           // 迭代实现
    // bt.PrintPreOrder();

    // testing RSum() 
    // test case: 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTree<int> bt;
    // bt.Create(8);
    // cout << "----------------" << endl;
    // cout << bt.RSum() << endl;

    // testing RTotalDeg2Nodes() 
    // test case: 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTree<int> bt;
    // bt.Create(8);
    // cout << "----------------" << endl;
    // cout << bt.RTotalDeg2Nodes() << endl;

    // testing maxDepth()
    // test case: 3 5 4 9 7 2 -1 -1 -1 -1 -1 -1 -1 -1
    // BinaryTree<int> bt;
    // bt.Create(8);
    // cout << "----------------" << endl;
    // cout << bt.maxDepth() << endl;

    ////////////////////////// Binary search tree /////////////////////////
    // test case: 9 4 7 17 10 1 25 5
    //             9
    //           /   \
    //          4     17
    //         / \   /  \
    //        1   7 10  25
    //           /
    //          5
    // Inorder : 1 4 5 7 9 10 17 25

    // Create() test
    // BinarySearchTree<int> bst;
    // bst.Create();
    // bst.PrintInorder();

    // Search() test
    // BinarySearchTree<int> bst;
    // bst.Create();
    // auto p = bst.Search(7);
    // cout << p->data << endl;
    // cout << p->lc->data << endl;
    
    // Delete() test
    // Delete root node
    BinarySearchTree<int> bst;
    bst.Create();
    bst.PrintInorder();
    bst.Delete(9);
    cout << endl;
    cout << "GetRootValue() is : " << bst.GetRootValue() << endl; 
    bst.PrintInorder();

    // delete leaf node
    // BinarySearchTree<int> bst;
    // bst.Create();
    // bst.PrintInorder();
    // cout << endl;
    // bst.Delete(5);
    // bst.PrintInorder();
    return 0;
}