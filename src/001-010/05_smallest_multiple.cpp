// https://www.hackerrank.com/contests/projecteuler/challenges/euler005

#include <iostream>
#include <cmath>
#include <vector>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto computePrimes(long long n) {
    std::vector<long long> primes;
    std::vector<char> sieve(n + 1, 0);
    for (auto i = 2; i < sieve.size(); i++) {
        if (sieve[i] == 0) {
            primes.emplace_back(i);
            for (auto j = 2 * i; j < sieve.size(); j += i) {
                sieve[j] = 1;
            }
        }
    }
    return primes;
}

auto highestPowerOf(long long x, long long limit) {
    int power = log(limit) / log(x);
    return pow(x, power);
}

auto smallestMultiple(long long n) {
    auto primes = computePrimes(n);
    auto result = 1;
    for (auto &prime: primes) {
        result *= highestPowerOf(prime, n);
    }
    return result;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();

        std::cout << smallestMultiple(n) << std::endl;
    }
}