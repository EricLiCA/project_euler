// https://www.hackerrank.com/contests/projecteuler/challenges/euler006

#include <iostream>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

auto gaussSum(long long n) {
    return ((n + 1) * n) / 2;
}

auto sumOfSquares(long long n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

auto sumSquareDifference(long long n) {
    auto sum = gaussSum(n);
    return sum * sum - sumOfSquares(n);
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();

        std::cout << sumSquareDifference(n) << std::endl;
    }
}