// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-15

#include "ADT.h"

struct Operator Create(char sym) {
    Operator op;
    op.symbol = sym;
    switch(sym) {
        case '+':
            op.priority = 1;
            break;
        case '-':
            op.priority = 1;
            break;
        case '*':
            op.priority = 2;
            break;
        case '/':
            op.priority = 2;
            break;
    }
    return op;
}

bool isOperator(char in) {
    if(in == '+' || in == '-' || in == '*' || in == '/')
        return true;
    return false;
}