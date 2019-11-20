#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::vector;
using std::endl;

unsigned long fibRecursive(unsigned long n){
        if (n == 0) return 1;
        if (n == 1) return 1;
        return fibRecursive(n - 1) + fibRecursive(n -2);
}

unsigned long fibIterative(const unsigned long n){
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

unsigned measureTime(unsigned n, unsigned long func (unsigned long)){
    const auto start = steady_clock::now();

    volatile unsigned long x;

    x = func(n);

    const auto end = steady_clock::now();
    const auto diff = end - start;
    const auto ysec = duration_cast<microseconds>(diff).count();

    return ysec;

}

int main(){
    vector<unsigned> recursive;
    vector<unsigned> iterative;
    const unsigned n = 40;

    std::ofstream ofile("output.csv");

    for(unsigned i = 2; i <= n; i++){
        ofile << i << "; ";
        ofile << measureTime(i, fibRecursive) << "; ";
        ofile << measureTime(i, fibIterative) << endl;
    }

    //std::cout << "\nTook: " <<  measureTime(40, fibRecursive) << " ys" << std::endl;
}
