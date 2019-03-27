// https://www.hackerrank.com/contests/projecteuler/challenges/euler008

#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

struct Data {
    std::string series;
    long long k;
};

auto getData() {
    long long n;
    Data data;
    std::cin >> n >> data.k;
    std::cin.ignore();
    std::getline(std::cin, data.series);
    return data;
}

auto toInt(char c) {
    return c - '0';
}

auto largestProductInASeries(const std::string &series, const long long k) {
    long long low = 0;
    long long currentProduct = 0LL, highestProduct = 0LL;

    auto charMultiply = [](long long res, char c) { return res * toInt(c); };

    while (low + k - 1 < series.size()) {
        if (currentProduct == 0) {
            currentProduct = std::accumulate(series.begin() + low, series.begin() + low + k, 1LL, charMultiply);
        } else {
            currentProduct /= toInt(series[low - 1]);
            currentProduct *= toInt(series[low + k - 1]);
        }

        if (currentProduct == 0) {
            auto zero = std::find(series.begin() + low, series.begin() + low + k, '0');
            low += zero - (series.begin() + low) + 1;
        } else {
            low++;
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