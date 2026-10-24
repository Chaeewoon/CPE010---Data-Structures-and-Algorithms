#ifndef SUPP_H
#define SUPP_H

template <typename T>
void InsertionSort(T arr[], int arrSize){
    int k = 1, j; 
    T temp;

    while(k < arrSize){
        temp = arr[k];
        j = k -1;
        while(j >= 0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        k++;
    }
}

//quicksort Helper
template <typename T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSortInsert(T arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        InsertionSort(arr + low, pivotIndex - low);
        InsertionSort(arr + pivotIndex + 1 , high-pivotIndex);
    }
}
#endif