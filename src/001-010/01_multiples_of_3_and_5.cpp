// https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <iostream>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto sumOfMultiplesOf(long long x, long long limit) {
    limit--;
    auto highestMultiple = limit - limit % x;
    auto numberOfMultiples = limit / x;
    return (x + highestMultiple) * numberOfMultiples / 2;
}

auto multiplesOf3And5(long long n) {
    return sumOfMultiplesOf(3, n) + sumOfMultiplesOf(5, n) - sumOfMultiplesOf(15, n);
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << multiplesOf3And5(n) << std::endl;
    }
}