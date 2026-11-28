Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int total = 0;
        for (int num : nums) {
            total += (num >> i) & 1;
        }
        res += total * (nums.size() - total);
    }
    return res;
}

int main() {
    vector<int> nums = {4, 1, 2};
    cout << totalHammingDistance(nums) << endl;
    return 0;
}

This code computes the total Hamming distance of all pairs of elements in the given integer array. The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

In this code, we iterate over all possible bits from least significant to most significant bit (from 0 to 31, inclusive). For each bit, we count the number of numbers in the array that have that bit set. Then, for each number in the array, we shift the number to the right i bits and perform a bitwise AND operation with 1. This operation counts the number of bits in the number that are set. Finally, we multiply the total number of sets by the number of remaining numbers in the array to get the number of pairs of numbers that have this bit set. This is done in a nested loop to avoid multiple computations of the same bit.