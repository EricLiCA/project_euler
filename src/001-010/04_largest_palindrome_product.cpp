// https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto reverse(long long x) {
    auto result = 0;
    while (x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

bool isPalindrome(int x) {
    return reverse(x) == x;
}

auto palindromeCandidates() {
    std::vector<long long> candidates;
    for (auto i = 101; i < 1000; i++) {
        for (auto j = i; j < 1000; j++) {
            auto product = i * j;
            if (isPalindrome(product)) candidates.emplace_back(product);
        }
    }
    std::sort(candidates.begin(), candidates.end());
    return candidates;
}

auto largestPalindromeProduct(std::vector<long long> candidates, long long n) {
    auto it = std::lower_bound(candidates.begin(), candidates.end(), n);
    return it == candidates.begin() ? *it : *(it - 1);
}

int main() {
    auto candidates = palindromeCandidates();
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();

        std::cout << largestPalindromeProduct(candidates, n) << std::endl;
    }
}