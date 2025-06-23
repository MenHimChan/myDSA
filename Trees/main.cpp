// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-22

#include "ADT.h"

int main() {

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
    BinaryTree<int> bt;
    bt.Create(8);
    bt.PrintPreOrder_stk();
    bt.PrintInOrder_stk();
    bt.PrintPostOrder_stk();
    bt.PrintLevelOrder();
    return 0;   
}