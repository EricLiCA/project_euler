// https://www.hackerrank.com/contests/projecteuler/challenges/euler007

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto upperBoundOfNthPrime(long long n) {
    long long rossersTheoreticalUpperBound = n * (log(n) + log(log(n)));
    // Rosser's upper bound only works for n >= 6. 11 is the 5th prime.
    return std::max(11LL, (long long) std::ceil(rossersTheoreticalUpperBound));
}

auto computePrimesUntil(long long n) {
    std::vector<long long> primes;
    std::vector<char> sieve(n + 1, 0);
    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i] == 0) {
            primes.emplace_back(i);
            for (int j = 2 * i; j < sieve.size(); j += i) {
                sieve[j] = 1;
            }
        }
    }
    return primes;
}

auto nthPrime(long long n) {
    return computePrimesUntil(upperBoundOfNthPrime(n))[n - 1];
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << nthPrime(n) << std::endl;
    }
}