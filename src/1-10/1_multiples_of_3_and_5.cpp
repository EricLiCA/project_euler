// https://www.hackerrank.com/contests/projecteuler/challenges/euler001

#include <iostream>

void getData(long long &n) {
    std::cin >> n;
}

long long sumOfMultiplesOfXBelowN(long long x, long long n) {
    n--;
    long long highestMultipleOfXBelowN = n - n % x;
    long long numberOfMultiplesBelowN = n / x;
    return (x + highestMultipleOfXBelowN) * numberOfMultiplesBelowN / 2;
}

long long multiplesOf3And5(long long n) {
    return sumOfMultiplesOfXBelowN(3, n) + sumOfMultiplesOfXBelowN(5, n) - sumOfMultiplesOfXBelowN(15, n);
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