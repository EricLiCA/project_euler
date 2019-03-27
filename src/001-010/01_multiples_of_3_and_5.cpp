// https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <iostream>

void getData(long long &n) {
    std::cin >> n;
}

long long sumOfMultiplesOf(long long x, long long limit) {
    limit--;
    long long highestMultiple = limit - limit % x;
    long long numberOfMultiples = limit / x;
    return (x + highestMultiple) * numberOfMultiples / 2;
}

long long multiplesOf3And5(long long n) {
    return sumOfMultiplesOf(3, n) + sumOfMultiplesOf(5, n) - sumOfMultiplesOf(15, n);
}

int main() {
    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        long long n;
        getData(n);

        std::cout << multiplesOf3And5(n) << std::endl;
    }
}