// https://www.hackerrank.com/contests/projecteuler/challenges/euler015

#include <iostream>
#include <vector>

auto getData() {
    int n, m;
    std::cin >> n >> m;
    return std::pair<int, int>(n, m);
}

long latticePaths(int n, int m) {
    if (m < n) return latticePaths(m, n);

    std::vector<unsigned long> dp(n + 1, 1);

    for (auto i = 0; i < m; i++) {
        for (auto j = 1; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - 1]) % long(1e9 + 7);
        }
    }

    return dp[n];
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto data = getData();
        std::cout << latticePaths(data.first, data.second) << std::endl;
    }
}