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
    auto candidateLimit = sqrt(n);
    for (auto candidate = 2; candidate <= candidateLimit; candidate++) {
        while (n % candidate == 0) n /= candidate;
        if (n == 1) return candidate;
    }
    return n;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();

        std::cout << largestPrimeFactor(n) << std::endl;
    }
}