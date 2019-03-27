// https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <iostream>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto sumOfMultiplesOf(long long x, long long limit) {
    limit--;
    long long highestMultiple = limit - limit % x;
    long long numberOfMultiples = limit / x;
    return (x + highestMultiple) * numberOfMultiples / 2;
}

auto multiplesOf3And5(long long n) {
    return sumOfMultiplesOf(3, n) + sumOfMultiplesOf(5, n) - sumOfMultiplesOf(15, n);
}

int main() {
    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << multiplesOf3And5(n) << std::endl;
    }
}