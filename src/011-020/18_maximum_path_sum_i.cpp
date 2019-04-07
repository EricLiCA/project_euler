// https://www.hackerrank.com/contests/projecteuler/challenges/euler018

#include <iostream>
#include <vector>

auto getData() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> triangle;
    triangle.reserve(n);
    for (int i = 0; i < n; i++) {
        std::vector<int> row(i + 1);
        for (int j = 0; j < i + 1; j++) {
            std::cin >> row[j];
        }
        triangle.emplace_back(row);
    }
    return triangle;
}

auto maximumPathSum(std::vector<std::vector<int>> triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    return triangle.front().front();
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto triangle = getData();
        std::cout << maximumPathSum(triangle) << std::endl;
    }
}