Here is the minimal C++ code that solves the given problem:

#include <iostream>
#include <algorithm>
#include <cmath>

int minBitFlips(int start, int goal) {
    int flips = std::abs(start - goal);
    return flips;
}

int main() {
    int start, goal;
    std::cout << "Enter start and goal: ";
    std::cin >> start >> goal;

    std::cout << "Minimum Bit Flips: " << minBitFlips(start, goal) << std::endl;

    return 0;
}
This program first takes as input the start and goal integers. It then calculates the absolute difference between the start and goal, which represents the number of bit flips needed to convert the start to the goal. The result is then printed to the console.