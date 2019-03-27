// https://www.hackerrank.com/contests/projecteuler/challenges/euler003

#include <iostream>
#include <cmath>
#include <algorithm>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto largestPrimeFactor(long long n) {
    long long largest = 1;
    auto candidateLimit = sqrt(n);
    for (auto candidate = 2; candidate <= candidateLimit; candidate++) {
        if (n % candidate == 0) {
            largest = candidate;
            while (n % candidate == 0) n /= candidate;
        }
    }
    return std::max(largest, n);
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();

        std::cout << largestPrimeFactor(n) << std::endl;
    }
}