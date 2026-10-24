#include <iostream>
#include "sortingAlgo.h"
#include <chrono>


int main(){
    const int maxSize = 100000;
    int arr[maxSize];
    int testCases[] = {1000, 10000, 100000};
    int repetitions = 100;


    for(int i = 0; i < maxSize; i++){
        arr[i] = i + 1;
    }


    for(int t = 0; t < 3; t++){
        int n = testCases[t];
        int dataFind = n;


        long long linearTotal = 0;
        long long binaryTotal = 0;


        for(int r = 0; r < repetitions; r++){
            auto startLinear = std::chrono::high_resolution_clock::now();
            linearSearch(n, dataFind, arr);
            auto endLinear =std::chrono::high_resolution_clock::now();


            linearTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(endLinear - startLinear).count();


            auto startBinary = std::chrono::high_resolution_clock::now();
            binarySearchArr(n, dataFind, arr);
            auto endBinary = std::chrono::high_resolution_clock::now();


            binaryTotal += std::chrono::duration_cast<std::chrono::nanoseconds>(endBinary - startBinary).count();
        }


        std::cout << "\nArray Size: " << n << '\n';
        std::cout << "Linear Search Average Runtime: " << linearTotal / repetitions << " ns\n";
        std::cout << "Binary Search Average Runtime: "<< binaryTotal / repetitions << " ns\n";
    }


    return 0;
}



