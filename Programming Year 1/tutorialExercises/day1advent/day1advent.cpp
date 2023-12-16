#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> calories = { 0 };

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "") {
            calories.push_back(0);
        }
        else {
            calories.back() += std::stoi(line);
        }
    }

    std::partial_sort(calories.begin(), calories.begin() + 3, calories.end(), std::greater<int>{});
    std::cout << "Part 1: " << calories[0] << '\n';
    std::cout << "Part 2: " << std::accumulate(calories.begin(), calories.begin() + 3, 0) << '\n';

    return 0;
}