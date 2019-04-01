// https://www.hackerrank.com/contests/projecteuler/challenges/euler016

#include <iostream>
#include <vector>
#include <numeric>

auto getData() {
    int n;
    std::cin >> n;
    return n;
}

auto sumOfDigits(unsigned long x) {
    auto sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

auto powerDigitSum(int n) {
    std::vector<unsigned long> digits;
    const unsigned long base = 1000000000;

    digits.emplace_back(1);
    for (auto i = 0; i < n; i++) {
        auto carry = 0;
        for (auto &digit: digits) {
            auto doubled = digit * 2 + carry;
            digit = doubled % base;
            carry = doubled / base;
        }
        if (carry) digits.emplace_back(carry);
    }

    auto sum = std::accumulate(digits.begin(), digits.end(), 0,
                               [](int acc, unsigned long x) { return acc + sumOfDigits(x); });

    return sum;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << powerDigitSum(n) << std::endl;
    }
}