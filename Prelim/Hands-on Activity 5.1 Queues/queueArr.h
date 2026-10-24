#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template<typename T>
class QueueArr{
private:
    T *q_arr;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    //constructor
    QueueArr(int capacity){
        q_capacity = capacity;
        q_arr = new T[q_capacity];
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    //copy constructor
    QueueArr(const QueueArr<T>& other){
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_arr = new T[q_capacity];
        for(int i = 0; i < q_capacity; i++){
            q_arr[i] = other.q_arr[i];
        }
    }

    //copy assignment operator
    QueueArr<T>& operator=(const QueueArr<T>& other){
        if (this == &other){
            return *this;
        }
        delete[] q_arr;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_arr = new T[q_capacity];
        for(int i = 0; i < q_capacity; i++){
            q_arr[i] = other.q_arr[i];
        }
        return *this;
    }

    //Destructor
    ~QueueArr(){
        delete[] q_arr;
    }

    //check if empty
    bool isEmpty(){
        return q_size == 0;
    }
    //check the size
    int size(){
        return q_size;
    }
    //clear the queue
    void clear(){
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }
    //check the fornt
    T front(){
        if(isEmpty()) return T();
        return q_arr[q_front];
    }

    //check the back
    T back(){
        if(isEmpty()) return T();
        return q_arr[q_back];
    }

    //enqueue 
    void enqueue(const T& value){
        if(q_size == q_capacity){
            std::cout << "Queue Overflow" << std::endl;
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_arr[q_back] = value;
        q_size++;
    }

    //dequeue
    T dequeue(){
        if(isEmpty()) return T();
        T value = q_arr[q_front];
        q_front = (q_front + 1) % q_capacity;
        q_size--;
        return value;
    }
};

#endif