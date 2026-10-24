#include "node.h"

#ifndef SEARCHALGO_H
#define SEARCHALGO_H

template <typename T>
void linearSeachArr(int arrSize, T dataFind , T list[] ){

    for(int i = 0; i < arrSize; i++){
        if(dataFind == list[i]){
            std::cout << "Searching is successful,\n";
            return;
        }
    }

    std::cout << "Searching is Unsuccessful" << std::endl;
}


template <typename T>
void linearSearchLL(Node<T> *head, T dataFind){
    while(head != nullptr){
        if(head->data == dataFind){
            std::cout <<"Searching is successful,\n";
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is Unsuccessful" << std::endl;

}

template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T> *last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){

        slow = slow->next;

        fast = fast->next->next;
    }

    return slow;
}


template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    //last node is set to NULL.
    Node<T>* last = nullptr;

    //Middle element is calculated using the two pointers
    while( start != last){

        Node<T>* middle = getMiddle(start, last);

        if(middle->data == dataFind){
            std::cout << "The data was found!\n";
            return;
        }

        if(middle->data > dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }

     std::cout << "Searching is Unsuccessful" << std::endl;
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    
    int low = 0, up = arrSize-1, middle;

    while( low <= up){
        middle = (int)((low+up)/2);

        if (dataFind == list[middle]){
            std::cout << "The search element is found \n";
            return;
        }
        else if( dataFind < list[middle]){
            up = middle-1;
        }else{
            low = middle+1;
        }
    }
    std::cout << "The search element is not found \n";
}

#endif