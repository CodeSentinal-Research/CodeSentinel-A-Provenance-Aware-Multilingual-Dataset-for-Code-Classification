Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> prefixSum(s.size() + 1);

    for (size_t i = 0; i < s.size(); ++i) {
        prefixSum[i + 1] = prefixSum[i] + s[i] - 'a' + 1;
    }

    for (const auto& sum : prefixSum) {
        std::cout << sum << ' ';
    }

    return 0;
}

This code reads the input string and calculates the prefix sum array for the character values. It uses the formula `prefixSum[i + 1] = prefixSum[i] + s[i] - 'a' + 1` to calculate the prefix sum. This formula takes the sum of the prefix sum array so far and the value of the current character, and then adds 1 to it to convert the character to its position in the alphabet.