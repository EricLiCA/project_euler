// https://www.hackerrank.com/contests/projecteuler/challenges/euler002

#include <iostream>
#include <algorithm>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto evenFibonacciNumbers(long long n) {
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
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << evenFibonacciNumbers(n) << std::endl;
    }
}