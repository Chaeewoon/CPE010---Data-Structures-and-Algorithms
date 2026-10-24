#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"


const int max_size = 100;

void displayArr(int arr[]);

int main(){
    //create an array containing 100 randomly generated values
    int unsortedArr[max_size];
    srand(time(0));
    for(int i= 0; i < max_size; i++){
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    std::cout << "Bubble Sort:\n";
    bubbleSort(unsortedArr, max_size);
    displayArr(unsortedArr);

    std::cout << "Selection Sort:\n";
    selectionSort(unsortedArr, max_size);
    displayArr(unsortedArr);

    std::cout << "Insertion Sort:\n";
    InsertionSort(unsortedArr, max_size);
    displayArr(unsortedArr);
    return 0;
}

//display function to display all the elements inside the function
void displayArr(int arr[]){
    for(int i = 0; i < max_size; i++){
        std::cout<< arr[i] <<" ";
    }
    std::cout << std::endl;
}
