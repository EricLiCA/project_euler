// https://www.hackerrank.com/contests/projecteuler/challenges/euler012

#include <iostream>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

long long highlyDivisibleTriangularNumber(int n) {
    return 0LL;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << highlyDivisibleTriangularNumber(n) << std::endl;
    }
}