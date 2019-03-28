// https://www.hackerrank.com/contests/projecteuler/challenges/euler013

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <cmath>

auto getData() {
    int n;
    std::cin >> n;
    std::vector <std::string> nums(n);
    std::copy_n(std::istream_iterator<std::string>(std::cin), n, nums.begin());
    return nums;
}

auto maxDigitNum(int digits) {
    auto result = 0LL;
    for (auto i = 0; i < digits; i++) {
        result *= 10;
        result += 9;
    }
    return result;
}

auto largeSum(std::vector <std::string> &nums, long long maxDigitsNum) {
    auto firstDigitsSum = [&](long long digits, std::string &num) {
        return digits + std::stoll(
                num.substr(0, log10(maxDigitsNum) + 1 + log10(nums.size())));
    };
    auto firstDigits = std::accumulate(nums.begin(), nums.end(), 0LL, firstDigitsSum);
    while (firstDigits > maxDigitsNum) {
        firstDigits /= 10;
    }
    return firstDigits;
}

int main() {
    auto nums = getData();
    std::cout << largeSum(nums, maxDigitNum(10)) << std::endl;
}