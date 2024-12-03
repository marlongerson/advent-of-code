#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::vector<int>> ParseInput() {
    std::vector<std::vector<int>> input;
    std::ifstream inputFile("input.txt");
    std::string temp;

    while (std::getline(inputFile, temp)) {
        std::vector<int> data;
        std::stringstream ss(temp);
        while (std::getline(ss, temp, ' ')) {
            data.emplace_back(std::stoi(temp));
        }
        input.emplace_back(move(data));
    }

    return input;
}

template <typename T = std::less<int>>
bool IsReportSafe(const std::vector<int>& report, T cmp) {
    for (int i = 1; i < report.size(); i++) {
        // Levels must be all increasing or all decreasing.
        if (!cmp(report[i], report[i - 1])) {
            return false;
        }
        // Levels must differ by at least one and at most three.
        int diff = abs(report[i] - report[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> reports = ParseInput();
    int result = 0;
    for (const auto& report : reports) {
        if (IsReportSafe(report, std::less<int>{}) || IsReportSafe(report, std::greater<int>{})) {
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}