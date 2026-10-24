#include <iostream>
#include <chrono>
#include <random>

// SUPPLEMENTARY #1
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

// SUPPLEMENTARY #2: PART 1
int rpower(int x, int n){
    if(n == 0){
        return 1;
    }
    else{
        return x * rpower(x, n - 1);
    }
}

// SUPPLEMENTARY #2: PART 2
int brpower(int x, int n){
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
    // =========================
    // SUPPLEMENTARY PROBLEM 1
    // =========================
    const int n = 100;
    int A[n];

    // Generate 100 unique values
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

    std::cout << "=== Problem 1: Unique Elements ===\n";
    std::cout << "Array Size: " << n << "\n";
    std::cout << "Result: " << result << "\n";
    std::cout << "Execution Time: " << executionTime.count() << " ns\n\n";

    // =========================
    // SUPPLEMENTARY PROBLEM 2: RPOWER
    // =========================
    auto start1 = std::chrono::high_resolution_clock::now();
    int result1 = rpower(2, 30);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    // =========================
    // SUPPLEMENTARY PROBLEM 2: BRPOWER
    // =========================
    auto start2 = std::chrono::high_resolution_clock::now();
    int result2 = brpower(2, 30);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);

    std::cout << "=== Problem 2: Power ===\n";
    std::cout << "rpower result: " << result1 << "\n";
    std::cout << "rpower execution time: " << time1.count() << " ns\n\n";
    std::cout << "brpower result: " << result2 << "\n";
    std::cout << "brpower execution time: " << time2.count() << " ns\n";

    return 0;
}