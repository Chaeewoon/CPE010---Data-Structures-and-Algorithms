#include <iostream>
#include <chrono>
#include <random>

bool algo(int A[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i] == A[j]){
                return false;
            }
        }
    }
    return true;
}

long long rpower(int x, int n){
    if(n == 0){
        return 1;
    }
    else{
        return x * rpower(x, n - 1);
    }
}


long long brpower(int x, int n){
    int y = 0;


    if(n == 0){
        return 1;
    }
    else if(n % 2 == 1){
        y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }
    else{
        y = brpower(x, n / 2);
        return y * y;
    }
}


int main(){
    int sizes[] = {100, 1000, 10000};
    int numberOfSizes = 3;


    std::cout << "Problem 1: Unique Elements \n";
    std::cout << "Array Size\tExecution Time (ns)\n";


    for(int s = 0; s < numberOfSizes; s++){
        int n = sizes[s];
        int* A = new int[n];


        for(int i = 0; i < n; i++){
            A[i] = i + 1;
        }
        std::random_device rd;
        std::mt19937 gen(rd());


        for(int i = n - 1; i > 0; i--){
            std::uniform_int_distribution<> dist(0, i);
            int j = dist(gen);


            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }


        auto start = std::chrono::high_resolution_clock::now();
        bool result = algo(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);


        std::cout << n << "\t\t" << executionTime.count() << " ns\n";


        delete[] A;
    }

    int x = 2;
    int powers[] = {100, 1000, 10000};
    int numberOfPowers = 3;


    std::cout << "\n Problem 2: Power \n";
    std::cout << "x = " << x << "\n\n";
    std::cout << "n\t" << "rpower (ns)\t" << "brpower (ns)\n";


    for(int i = 0; i < numberOfPowers; i++){
        int n = powers[i];

        auto start1 = std::chrono::high_resolution_clock::now();
        int result1 = rpower(x, n);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

        auto start2 = std::chrono::high_resolution_clock::now();
        int result2 = brpower(x, n);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);


        std::cout << n << "\t" << time1.count() << "\t\t"<< time2.count() << "\n";
    }
    return 0;
}



