#include <iostream>
#include <chrono>
#include "sortingAlgo.h"

const int maxSize = 10000;
int arr[maxSize];

int main() {
    int sizes[] = {100, 1000, 10000};

    for(int s = 0; s < 3; s++) {
        int n = sizes[s];

        std::cout << "\nTable 14-2 (" << n << ")" << std::endl;
        std::cout << "\t\tBubble Sort\tMerge Sort" << std::endl;

        for(int i = 0; i < n; i++)
            arr[i] = i + 1;

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto bubbleBest = std::chrono::duration<double, std::milli>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        auto mergeBest = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "Best Case\t" << bubbleBest << " ms\t" << mergeBest << " ms" << std::endl;

        for(int i = 0; i < n; i++)
            arr[i] = n - i;

        start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        end = std::chrono::high_resolution_clock::now();
        auto bubbleWorst = std::chrono::duration<double, std::milli>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        auto mergeWorst = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "Worst Case\t" << bubbleWorst << " ms\t" << mergeWorst << " ms" << std::endl;
    }

    return 0;
}