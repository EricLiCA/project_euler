// https://www.hackerrank.com/contests/projecteuler/challenges/euler003

#include <iostream>
#include <cmath>
#include <algorithm>

void getData(long long &n) {
    std::cin >> n;
}

long long largestPrimeFactor(long long n) {
    long long largest = 1;
    double candidateLimit = sqrt(n);
    for (long long candidate = 2; candidate <= candidateLimit; candidate++) {
        if (n % candidate == 0) {
            largest = candidate;
            while (n % candidate == 0) n /= candidate;
        }
    }
    return std::max(largest, n);
}

int main() {
    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        long long n;
        getData(n);

        std::cout << largestPrimeFactor(n) << std::endl;
    }
}