// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-07-07

#include "ADT.h"

int arr_rchild_idx(int i, int arr_size) {
    int idx = 2 * i + 2;
    if(i < 0 || i >= arr_size || idx >= arr_size)
        return -1;
    return idx;
}

int arr_lchild_idx(int i, int arr_size) {
    int idx = 2 * i + 1;
    if(i < 0 || i >= arr_size || idx >= arr_size)
        return -1;
    return idx;
}

int arr_parent_idx(int i, int arr_size) {
    int idx = (i - 1) / 2;
    if(i <= 0 || i >= arr_size)
        return -1;
    return idx;
}