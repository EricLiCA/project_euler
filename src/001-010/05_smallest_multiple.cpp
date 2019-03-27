// https://www.hackerrank.com/contests/projecteuler/challenges/euler005

#include <iostream>
#include <cmath>
#include <vector>

void getData(long long &n) {
    std::cin >> n;
}

std::vector<long long> computePrimes(long long n) {
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

long long highestPowerOf(long long x, long long limit) {
    int power = (int) (log(limit) / log(x));
    return pow(x, power);
}

long long smallestMultiple(long long n) {
    auto primes = computePrimes(n);
    int result = 1;
    for (auto &prime: primes) {
        result *= highestPowerOf(prime, n);
    }
    return result;
}

int main() {
    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        long long n;
        getData(n);

        std::cout << smallestMultiple(n) << std::endl;
    }
}