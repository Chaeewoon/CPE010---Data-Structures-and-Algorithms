#include <iostream>
#include "queueArr.h"

int main(){
    QueueArr<int> q(5);

    //checking if the queue is empty and its size
    std::cout <<"Is the queue empty: "<<q.isEmpty() << std::endl;
    std::cout <<"The size of the queue is: "<<q.size() << std::endl;

    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(7);

    std::cout <<"\nAfter enqueuing 6, 9 and 7" << std::endl;

    std::cout <<"Is the queue empty: "<<q.isEmpty() << std::endl;
    std::cout <<"The size of the queue is: "<<q.size() << std::endl;
    std::cout <<"The front of the queue is: " << q.front() << std::endl;
    std::cout <<"The back of the queue is: " << q.back() << std::endl;

    std::cout <<"\nDequeuing an element: " << q.dequeue() << std::endl;

    std::cout <<"\nAfter dequeuing an element" << std::endl;
    std::cout <<"Is the queue empty: "<<q.isEmpty() << std::endl;
    std::cout <<"The size of the queue is: "<<q.size() << std::endl;
    std::cout <<"The front of the queue is: " << q.front() << std::endl;
    std::cout <<"The back of the queue is: " << q.back() << std::endl;

    //copy constructor
    QueueArr<int> q2 = q;
    std::cout <<"\nAfter copying the queue" << std::endl;
    std::cout <<"Is the queue empty: "<<q2.isEmpty() << std::endl;
    std::cout <<"The size of the queue is: "<<q2.size() << std::endl;
    std::cout <<"The front of the queue is: " << q2.front() << std::endl;
    std::cout <<"The back of the queue is: " << q2.back() << std::endl;

    //copy assignment operator
    QueueArr<int> q3(9);
    q3 = q;
    std::cout <<"\nAfter assigning the queue" << std::endl;
    std::cout <<"Is the queue empty: "<<q3.isEmpty() << std::endl;
    std::cout <<"The size of the queue is: "<<q3.size() << std::endl;
    std::cout <<"The front of the queue is: " << q3.front() << std::endl;
    std::cout <<"The back of the queue is: " << q3.back() << std::endl;


    //testing the clear
    q.clear();
    std::cout <<"\nAfter clearing the queue" << std::endl;
    std::cout <<"Is the queue empty: "<<q.isEmpty() << std::endl;
    std::cout <<"The size of the queue is: "<<q.size() << std::endl;

    //testing the queue overflow
    QueueArr<int> q4(2);
    std::cout <<"\nOverflowing the Queue" << std::endl;
    q4.enqueue(1);
    q4.enqueue(2);
    q4.enqueue(3);

    return 0;
}