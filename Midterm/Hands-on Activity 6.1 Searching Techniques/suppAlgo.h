#include "node.h"

#ifndef SUPPALGO_H
#define SUPPALGO_H

//problem 1
template <typename T>
int sequentialSearchArr(int arrSize, T dataFind, T list[]){
    int comparison = 0;
    for(int i = 0; i < arrSize; i++){
        comparison++;
        if(dataFind == list[i]){
            std::cout <<"Searching is Successful";
            return comparison;
        }
    }
    std::cout <<"Searching is Unsuccessful";
    return comparison;
}

template <typename T>
int sequentialSearchLL(Node<T>* head, T dataFind){
    int comparison = 0;
    while(head != nullptr){
        comparison++;
        if(dataFind == head->data){
            std::cout <<"Searching is Successful";
            return comparison;
        }
        head = head->next;
    }
    std::cout <<"Searching is Unsuccessful";
    return comparison;
}


//problem 2
template <typename T>
int repetitionSearchArr(int arrSize, T dataFind, T list[]){
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(dataFind == list[i]){
            count++;
        }
    }
    return count;
}

template <typename T>
int repetitionSearchLL(Node<T>* head, T dataFind){
    int count = 0;
    while(head != nullptr){
        if(dataFind == head->data){
            count++;
        }
        head = head->next;
    }
    return count;
}

//problem 3
template <typename T>
void binarySearchAlgo(int arrSize, T dataFind, T list[]){
    int low = 0, up = arrSize -1, middle;

    while(low <= up){
        middle = (int)((low+up)/2);
        if (dataFind == list[middle]){
            std::cout <<"The element was found";
            return;
        }else if(dataFind < list[middle]){
            up = middle - 1;
        }else{
            low = middle +1;
        }
    }
    std::cout <<"The element was not found";
}

//problem 4
template <typename T>
void binarySearchAlgoRecursive(T list[], int low, int up, T dataFind){
    if(low>up){
        std::cout <<"The element was not found";
        return;
    }
    int middle = (int)((low+up)/2);
    if(dataFind == list[middle]){
        std::cout << "The element was found";
        return;
    }else if( dataFind < list[middle]){
        binarySearchAlgoRecursive(list, low, middle-1, dataFind);
    }else{
        binarySearchAlgoRecursive(list ,middle+1, up, dataFind);
    }
}
#endif