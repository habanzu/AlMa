#include <iostream>
#include <chrono>

unsigned long fibRecursive(unsigned long n){
        if (n == 0) return 1;
        if (n == 1) return 1;
        return fibRecursive(n - 1) + fibRecursive(n -2);
}

unsigned long fibIterative(unsigned long n){
    if (n < 2) return 1;
    unsigned long fib_n = 0;
    unsigned long fib_n_minus_2 = 1;
    unsigned long fib_n_minus_1 = 1;
    for(unsigned i = 2; i <= n; ++i){
        fib_n = fib_n_minus_1 + fib_n_minus_2;
        fib_n_minus_2 = fib_n_minus_1;
        fib_n_minus_1 = fib_n;
    }
    return fib_n;
}

int main(){
    const auto start = std::chrono::steady_clock::now();
    std::cout << "Die 50. Fibonacci Zahl ist: " << fibRecursive(40) << std::endl;

    const auto end = std::chrono::steady_clock::now();
    const auto diff = end - start;
    const auto sec = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
    const auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();

    std::cout << "\nTook: " << sec << "." << msec << "s" << std::endl;
}
