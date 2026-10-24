#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

template <typename T>
void bubbleSort(T arr[], int maxSize){
    for(int i = 0; i < maxSize - 1; i++){
        for(int j = i+1; j < maxSize; j++){
            if(arr[i] > arr[j]){
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    for(int i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0 , j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

//merge sort
template <typename T>
void mergeSort(T arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low = 0;
    int up = arrSize - 1;
    int middle;


    while(low <= up){
        int middle = (low + up)/ 2;


        if(list[middle] == dataFind){
            return;
        }
        else if(list[middle] < dataFind){
            low = middle + 1;
        }
        else if(list[middle] > dataFind){
            up = middle - 1;
        }
    }
};


template <typename T>
void linearSearch(int arrSize, T dataFind, T list[]){
    //Step 1: I =0;
    int i = 0;
    //Repeat while I <= n
    while(i < arrSize){
        // If (item=data[i])
        if(dataFind == list[i]){
            return;
        }
        i++;
    }
};






#endif