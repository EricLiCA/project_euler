// https://www.hackerrank.com/contests/projecteuler/challenges/euler010

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto computePrimesUntil(long long n) {
    std::vector<long long> primes;
    std::vector<char> sieve(n + 1, 0);
    auto limit = sqrt(sieve.size());
    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i] == 0) {
            primes.emplace_back(i);
            if (i > limit) continue;
            for (int j = 2 * i; j < sieve.size(); j += i) {
                sieve[j] = 1;
            }
        }
    }
    return primes;
}

auto summationOfPrimes(long long n, std::vector<long long> primes) {
    auto sum = 0LL;
    for (auto &prime: primes) {
        if (prime <= n) sum += prime;
        else break;
    }
    return sum;
}

int main() {
    auto t = 0;
    const auto HACKERRANK_LIMIT = 1000000;
    auto primes = computePrimesUntil(HACKERRANK_LIMIT);
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << summationOfPrimes(n, primes) << std::endl;
    }
}