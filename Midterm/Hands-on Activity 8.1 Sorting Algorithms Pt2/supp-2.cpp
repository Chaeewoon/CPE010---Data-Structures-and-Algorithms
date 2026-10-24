#include <iostream>
#include "supp.h"

void displayAll(int arr[], int arrSize);

int main(){
    int exampleArr[] = {42, 21, 10, 15, 57, 67};
    int exampleSize = 6;

    std::cout << "Before sorting: ";
    displayAll(exampleArr, exampleSize);

    quickSortInsert(exampleArr, 0, exampleSize - 1);

    std::cout << "After sorting: ";
    displayAll(exampleArr, exampleSize);
    
    return 0;
}


void displayAll(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}