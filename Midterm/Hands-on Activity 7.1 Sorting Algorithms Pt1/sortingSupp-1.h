#ifndef SORTINGSUPP_H
#define SORTINGSUPP_H

//helper function
template <typename T>
int routine_smallest(T arr[], int k, int arrSize){
    int position = k;

    T smallestElement = arr[k];

    for(int j = k+ 1; j < arrSize; j++){
        if(arr[j] < smallestElement){
            smallestElement = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize){
    int min;

    for(int i = 0; i < arrSize; i++){
        min = routine_smallest(arr, i, arrSize);
        std::swap(arr[i], arr[min]);
    }
}

template <typename T>
void countVotes(T arr[], int arrSize){
    T currentVote = arr[0];
    int count = 1;
    
    for(int i = 1; i < arrSize; i++){
        if(arr[i] == currentVote){
            count++;
        } else {
            std::cout << "Candidate " << currentVote << " received " << count << " votes." << std::endl;
            currentVote = arr[i];
            count = 1;
        }
    }
    std::cout << "Candidate " << currentVote << " received " << count << " votes." << std::endl;
}

template <typename T>
void displayArray(T arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


#endif