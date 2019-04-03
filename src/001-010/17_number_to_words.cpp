// https://www.hackerrank.com/contests/projecteuler/challenges/euler017

#include <iostream>
#include <vector>
#include <string>

auto getData() {
    long long n;
    std::cin >> n;
    return n;
}

std::vector<int> groupsOfThousand(long long n) {
    std::vector<int> groups(4);
    for (int i = 0; i < 4 && n; i++) {
        groups[i] = n % 1000;
        n /= 1000;
    }
    return groups;
}

std::string numberToWords(long long n) {
    const std::vector <std::string> thousandSuffixes = {"", "Thousand", "Million", "Billion"};
    const std::vector <std::string> decaSuffixes = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
                                                    "Ninety"};
    const std::vector <std::string> tenToNineteen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                                                     "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const std::vector <std::string> oneToNine = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                                                 "Nine"};

    auto groups = groupsOfThousand(n);

    std::vector <std::string> strGroups(4);
    for (int i = 0; i < 4; i++) {
        auto prefix = "";
        auto hundreds = groups[i] / 100;
        if (hundreds) {
            strGroups[i] += prefix + oneToNine[hundreds - 1] + " Hundred";
            prefix = " ";
        }
        auto remaining = groups[i] % 100;
        if (remaining >= 10 && remaining < 20) {
            strGroups[i] += prefix + tenToNineteen[remaining - 10];
            prefix = " ";
        } else {
            if (remaining >= 20) {
                auto decas = remaining / 10;
                strGroups[i] += prefix + decaSuffixes[decas - 2];
                prefix = " ";
            }
            auto digit = remaining % 10;
            if (digit) {
                strGroups[i] += prefix + oneToNine[digit - 1];
                prefix = " ";
            }
        }
        if (i > 0 && !strGroups[i].empty()) {
            strGroups[i] += " " + thousandSuffixes[i];
        }
    }

    auto prefix = "";
    std::string result;
    for (int i = strGroups.size() - 1; i >= 0; i--) {
        if (!strGroups[i].empty()) {
            result += prefix + strGroups[i];
            prefix = " ";
        }
    }

    return result;
}

int main() {
    auto t = 0;
    std::cin >> t;
    for (auto testCase = 0; testCase < t; testCase++) {
        auto n = getData();
        std::cout << numberToWords(n) << std::endl;
    }
}