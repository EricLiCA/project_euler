// https://www.hackerrank.com/contests/projecteuler/challenges/euler006

#include <iostream>

void getData(long long &n) {
    std::cin >> n;
}

long long gaussSum(long long n) {
    return ((n + 1) * n) / 2;
}

long long sumOfSquares(long long n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

long long sumSquareDifference(long long n) {
    long long sum = gaussSum(n);
    return sum * sum - sumOfSquares(n);
}

int main() {
    int t = 0;
    std::cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        long long n;
        getData(n);

        std::cout << sumSquareDifference(n) << std::endl;
    }
}