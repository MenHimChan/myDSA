// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-15
#include "ADT.h"
#include <ctype.h>
#include <stdlib.h>

// aid function for parenthesis matching test 
bool isMatchPair(char opening, char closing) {
    if( (opening == '(' && closing == ')') ||
        (opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']')
    )
        return true;
    return false;
}

int main() {

    ////////////////////////////////////// Array stack /////////////////////////////////////////
    // Create() test
    // ArrayStack<int> st(5);
    // st.Create();
    // st.Display();

    // peek() test
    // ArrayStack<int> st(5);
    // st.Create();
    // st.Display();
    // cout << "st.peek(0): " << st.peek(0) << endl;
    // cout << "st.peek(2): " << st.peek(2) << endl;
    // cout << "st.peek(4): " << st.peek(4) << endl;

    // pop() test
    // ArrayStack<int> st(5);
    // int val;
    // if(st.pop(val))
    //     cout <<  "st.pop(val) = : " << val << endl;
    // else 
    //     cout << "The stack is empty, Not able to pop !" << endl;


    ///////////////////////////////////// LinkList stack ////////////////////////////////////
    // pop push GetSize Display test
    // LinklistStack<int> st;
    // int tmp;
    // cout << "---------------------------------------" << endl;
    // st.push(100);
    // st.push(10000);
    // st.push(1213);
    // st.push(4545);
    // st.Display();
    // cout << "---------------------------------------" << endl;
    // st.pop(tmp);
    // st.pop(tmp);
    // cout << "tmp is : " <<tmp << endl;
    // cout << "GetSize() is : " << st.GetSize() << endl;
    // st.Display();

    // Init() Display() test
    // LinklistStack<int> st;
    // st.Init();
    // st.Display();
    
    // peek test
    // LinklistStack<int> st;
    // st.Init();
    // st.Display();
    // cout << "st.peek(0) : " << st.peek(0) << endl;
    // cout << "st.peek(3) : " << st.peek(3) << endl;
    // cout << "st.peek(5) : " << st.peek(5) << endl;

    /////////////////////////////////// Stack excersise ////////////////////////////////////

    ///////////////////////////// parenthesis matching test ////////////////////////////////
    // char s[100];
    // cin.getline(s, 100);
    // LinklistStack<char> st;
    // for(int i = 0; s[i] != '\0'; i++) {
    //     char x;
    //     if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
    //         st.push(s[i]);
    //         // cout << "Push : " << s[i] << endl;
    //     }
    //     else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
    //         if(st.isEmpty())
    //             break;
    //         if(isMatchPair(st.peek(0), s[i])) {
    //             st.pop(x);
    //             // cout << "Pop : " << x;
    //         }
    //     }
    // }
    // st.Display();
    // if(st.isEmpty())
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;

    ///////////////////////////////////////  Converting from infix to postfix //////////////////////////////
    // char in[100];
    // LinklistStack<char> stack;
    // cin >> in;
    // for(int i = 0; in[i] != '\0'; i++) {
    //     if(in[i] == '(')                            // Opening 
    //         stack.push(in[i]);
    //     else if(in[i] == ')') {                     // closing
    //         char tmp;
    //         while(stack.peek(0) != '(' && !stack.isEmpty()) {            // Continue Poping while top elements is not '('
    //             stack.pop(tmp);
    //             cout << tmp;
    //         }
    //         stack.pop(tmp);
    //     }
    //     else if(isOperator(in[i])) {
    //         Operator op = Create(in[i]);            // op.symbol = in[i], op.priority 
    //         if(stack.isEmpty())
    //             stack.push(op.symbol);
    //         else {
    //             if(stack.peek(0) == '(')
    //                 stack.push(op.symbol);
    //             else {
    //                 Operator top = Create(stack.peek(0));
    //                 if(op.priority > top.priority)
    //                     stack.push(op.symbol);
    //                 else {
    //                     while(op.priority <= top.priority && !stack.isEmpty()) {
    //                         char x;
    //                         stack.pop(x);
    //                         cout << x;
    //                     }
    //                     stack.push(op.symbol);
    //                 }
    //             }
    //         }
    //     }
    //     else
    //         cout << in[i];
    // }
    // while(!stack.isEmpty()) {
    //     char tmp;
    //     stack.pop(tmp);
    //     cout << tmp;
    // }
    // cout << endl;
    // return 0;

    ///////////////////////////////////////// Evaluation of Postfix ////////////////////////////////////////
    // char in[100];
    // cin.getline(in, 100);
    // // cout << in;
    // LinklistStack<int> stack;
    // for(int i = 0; in[i] != '\0'; i++) {
    //     if(isdigit(in[i])) {
    //         int num = 0;
    //         while(isdigit(in[i])) {
    //             num = num * 10 + (in[i] - '0');
    //             i++;
    //         }
    //         stack.push(num);
    //     }
    //     else if(in[i] == ' ') continue;
    //     else {
    //         int x,y,MidAns;
    //         stack.pop(x);
    //         stack.pop(y);
    //         switch(in[i]) {
    //             case '+': MidAns = y + x; break;
    //             case '-': MidAns = y - x; break;
    //             case '*': MidAns = y * x; break;
    //             case '/': MidAns = y / x; break;
    //         }
    //         stack.push(MidAns);
    //     }
    // }
    // cout << stack.peek(0) << endl;

    ///////////////////////////////////////// Queue Implementation using 2 stacks ////////////////////////////////////////
    StackQueue<int> stackqueue;
    int tmp;
    stackqueue.Enqueue(1000);
    stackqueue.Enqueue(25252);
    stackqueue.Enqueue(123512);
    stackqueue.Dequeue(tmp);
    stackqueue.Dequeue(tmp);
    stackqueue.Enqueue(1019);
    stackqueue.Enqueue(7987);
    stackqueue.Dequeue(tmp);

    stackqueue.Display();


    return 0;
}
