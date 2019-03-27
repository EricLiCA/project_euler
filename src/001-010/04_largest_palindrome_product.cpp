// https://www.hackerrank.com/contests/projecteuler/challenges/euler004

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

void getData(long long &n) {
    std::cin >> n;
}

int reverse(int x) {
    int result = 0;
    while (x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

bool isPalindrome(int x) {
    return reverse(x) == x;
}

std::vector<int> palindromeCandidates() {
    std::vector<int> candidates;
    for (int i = 101; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int product = i * j;
            if (isPalindrome(product)) candidates.emplace_back(product);
        }
    }
    std::sort(candidates.begin(), candidates.end());
    return candidates;
}

long long largestPalindromeProduct(std::vector<int> candidates, long long n) {
    auto it = std::lower_bound(candidates.begin(), candidates.end(), n);
    return it == candidates.begin() ? *it : *(it - 1);
}

int main() {
    auto candidates = palindromeCandidates();

    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        long long n;
        getData(n);

        std::cout << largestPalindromeProduct(candidates, n) << std::endl;
    }
}