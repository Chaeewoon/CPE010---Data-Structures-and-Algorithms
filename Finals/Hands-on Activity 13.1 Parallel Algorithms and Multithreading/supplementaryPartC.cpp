
#include <iostream>
#include <thread>

template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    T* leftArray = new T[leftSize];
    T* rightArray = new T[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// Merge Sort with Multithreading
template <typename T>
void mergeSort(T arr[], int left, int right, int depth = 0) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        if (depth < 2) {
            std::thread t1([&]() {
                mergeSort(arr, left, middle, depth + 1);
            });

            mergeSort(arr, middle + 1, right, depth + 1);

            t1.join();
        }
        else {
            mergeSort(arr, left, middle, depth + 1);
            mergeSort(arr, middle + 1, right, depth + 1);
        }

        merge(arr, left, middle, right);
    }
}

int main() {
    int sampleArr[] = {38, 12, 27, 43, 9, 31, 18, 25};

    std::cout << "Original array: ";
    for (int n : sampleArr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    mergeSort(sampleArr, 0, 7);

    std::cout << "Sorted array: ";
    for (int n : sampleArr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

