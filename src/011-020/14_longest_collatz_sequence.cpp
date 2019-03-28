// https://www.hackerrank.com/contests/projecteuler/challenges/euler014

#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX 5000000

auto getData() {
    int n;
    std::cin >> n;
    return n;
}

int getCollatzSequenceLength(std::vector<int> &cache, long long x) {
    if (cache[x] != 0) return cache[x];

    if (x % 2 == 0) {
        cache[x] = getCollatzSequenceLength(cache, x >> 1) + 1;
        return cache[x];
    }

    auto temp = 3 * x + 1;
    auto count = 1;
    while (temp > MAX) {
        if (temp % 2 == 0) {
            temp >>= 1;
        } else {
            temp = 3 * temp + 1;
        }
        count++;
    }

    cache[x] = getCollatzSequenceLength(cache, temp) + count;
    return cache[x];
}

auto longestCollatzSequence(int n, std::vector<int> &cache, std::vector<int> &highestSoFar) {
    if (highestSoFar.size() > n) return highestSoFar[n];

    auto longestStarting = 1LL;
    cache[longestStarting] = 1;

    for (int startingNumber = highestSoFar.size(); startingNumber <= n; startingNumber++) {
        auto length = getCollatzSequenceLength(cache, startingNumber);
        if (length >= cache[highestSoFar.back()]) {
            highestSoFar.emplace_back(startingNumber);
        } else {
            highestSoFar.emplace_back(highestSoFar.back());
        }
    }

    return highestSoFar.back();
}

int main() {
    std::vector<int> cache(MAX + 1);
    std::vector<int> highestSoFar(2, 0);
    longestCollatzSequence(MAX, cache, highestSoFar);
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << longestCollatzSequence(n, cache, highestSoFar) << std::endl;
    }
}