// https://www.hackerrank.com/contests/projecteuler/challenges/euler012

#include <iostream>
#include <unordered_map>
#include <cmath>

auto getData() {
    int n;
    std::cin >> n;
    return n;
}

auto primeFactorCounts(int n) {
    std::unordered_map<int, unsigned> factorCounts;

    if (n % 2 == 0) {
        while (n % 2 == 0) {
            n >>= 1;
            factorCounts[2]++;
        }
        // remove one 2 since we divide by 2 to generate the triangle number
        // triangleNumber = x * (x + 1) / 2
        factorCounts[2]--;
    }

    auto limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        while (n % i == 0) {
            n /= i;
            factorCounts[i]++;
        }
        if (n == 1) break;
    }

    if (n != 1) factorCounts[n]++;

    return factorCounts;
}

auto numberOfFactors(std::unordered_map<int, unsigned> factorCounts) {
    int factors = 1;
    for (auto &factor: factorCounts) factors *= factor.second + 1;
    return factors;
}

auto triangleNumber(int n) {
    return (n * (n + 1)) >> 1;
}

auto highlyDivisibleTriangularNumber(int n) {
    auto x = 1;
    auto xFactors = numberOfFactors(primeFactorCounts(x));
    auto xPlusOneFactors = numberOfFactors(primeFactorCounts(x + 1));
    auto factors = xFactors * xPlusOneFactors;

    while (factors <= n) {
        x++;
        xFactors = numberOfFactors(primeFactorCounts(x + 1));
        std::swap(xFactors, xPlusOneFactors);
        factors = xFactors * xPlusOneFactors;
    }

    return triangleNumber(x);
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << highlyDivisibleTriangularNumber(n) << std::endl;
    }
}