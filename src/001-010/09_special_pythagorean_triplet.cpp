// https://www.hackerrank.com/contests/projecteuler/challenges/euler009

#include <iostream>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto isPythagoreanTriplet(long long a, long long b, long long c) {
    return a * a + b * b == c * c;
}

auto specialPythagoreanTriplet(long long n) {
    long long highestProduct = -1;
    for (long long a = 1; a < n / 3.0; a++) {
        long long b = n * (2 * a - n) / (2 * (a - n));
        long long c = n - a - b;
        if (a < b && b < c && isPythagoreanTriplet(a, b, c)) highestProduct = std::max(highestProduct, a * b * c);
    }
    return highestProduct;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << specialPythagoreanTriplet(n) << std::endl;
    }
}