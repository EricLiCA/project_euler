// https://www.hackerrank.com/contests/projecteuler/challenges/euler008

#include <iostream>
#include <string>
#include <numeric>

struct Data {
    std::string series;
    long long k;
};

auto getData() {
    long long n, k;
    Data data;
    std::cin >> n >> data.k;
    std::cin.ignore();
    std::getline(std::cin, data.series);
    return data;
}

auto largestProductInASeries(const std::string &series, const long long k) {
    long long low = 0, high = low + k - 1;
    long long currentProduct = 0LL, highestProduct = 0LL;

    bool initialized = false;
    auto charMultiply = [](long long res, char c) { return res * (c - '0'); };

    while (high < series.size()) {
        if (!initialized) {
            currentProduct = std::accumulate(series.begin() + low, series.begin() + high, 1LL, charMultiply);
            initialized = true;
        } else {
            currentProduct /= series[low - 1];
            currentProduct *= series[high];
        }

        if (currentProduct == 0) {
            initialized = false;
            low += k, high += k;
        } else {
            low++, high++;
        }

        highestProduct = std::max(highestProduct, currentProduct);
    }

    return highestProduct;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto data = getData();
        std::cout << largestProductInASeries(data.series, data.k) << std::endl;
    }
}