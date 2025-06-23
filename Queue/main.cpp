// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-06-18
#include "ADT.h"

int main() {

    /////////////////////////////// ArrayQueue basic ADT test ////////////////////////////////
    // int tmp;
    // ArrayQueue<int> fifo(5);
    // fifo.Enqueue(199);
    // fifo.Enqueue(24525);
    // fifo.Enqueue(1019);
    // fifo.Display();

    // fifo.Dequeue(tmp);
    // fifo.Dequeue(tmp);
    // fifo.Display();
    // cout << fifo.GetFront() << ' ' << fifo.GetRear();

    /////////////////////////////  ArrayCircularQueue basic ADT test ///////////////////////////////////
    // int tmp;
    // ArrayCircularQueue<int> fifo(6);
    // cout << "Enqueue 10012 123 1019 : " << endl;
    // fifo.Enqueue(10012);
    // fifo.Enqueue(123);
    // fifo.Enqueue(1019);
    // fifo.Display();

    // cout << "Dequeue 2 elements : " << endl;
    // fifo.Dequeue(tmp);
    // fifo.Dequeue(tmp);
    // fifo.Display();

    // cout << "Enqueue 2525 1019 2001 65 : " << endl;
    // fifo.Enqueue(2525);
    // fifo.Enqueue(1019);
    // fifo.Enqueue(2001);
    // fifo.Enqueue(64);
    // fifo.Display();
    // cout << "fifo.TotalElems() : " << fifo.TotalElems() << endl;

    ///////////////////////////// LinkedListQueue basic ADT test ///////////////////////////////////
    int tmp;
    LinkedListQueue<int> fifo;
    fifo.Enqueue(10012);
    fifo.Enqueue(123);
    fifo.Enqueue(1019);
    fifo.Display();

    fifo.Dequeue(tmp);
    fifo.Dequeue(tmp);
    fifo.Display();

    fifo.Enqueue(2552);
    fifo.Enqueue(123512);
    fifo.Enqueue(11412);
    fifo.Display();
    cout << "fifo.TotalElems() : " << fifo.TotalElems() << endl;
    cout << "fifo.GetAt(3) : "<< fifo.GetAt(3) << endl;
    
    return 0;
}