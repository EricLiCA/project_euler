// https://www.hackerrank.com/contests/projecteuler/challenges/euler002

#include <iostream>
#include <algorithm>

void getData(long long &n) {
    std::cin >> n;
}

long long evenFibonacciNumbers(long long n) {
    long long sum = 0;
    long long a = 1, b = 2;

    while (b <= n) {
        if (b % 2 == 0) sum += b;
        a += b;
        std::swap(a, b);
    }

    return sum;
}

int main() {
    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        long long n;
        getData(n);

        std::cout << evenFibonacciNumbers(n) << std::endl;
    }
}