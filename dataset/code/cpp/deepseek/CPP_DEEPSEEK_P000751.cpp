#include <iostream>
using namespace std;

int countSubseq(int nums[], int n, int target) {
    if (n == 0) {
        return (target == 0) ? 1 : 0;
    }
    return countSubseq(nums + 1, n - 1, target - nums[0]) + countSubseq(nums + 1, n - 1, target);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 5;

    cout << countSubseq(nums, n, target);

    return 0;
}
This C++ code defines a recursive function `countSubseq` that counts the number of subsequences whose sum equals `target` given the array `nums` and the size of `nums`. The function uses recursion to divide the problem into smaller problems and solve them. If `target` is 0, it returns 1 because the empty set is a valid subsequence. Otherwise, it calls the function recursively for each element in `nums`, subtracting the current element from `target` and incrementing the count for the two cases where the current element is included (`countSubseq(nums + 1, n - 1, target - nums[0])`) and not included (`countSubseq(nums + 1, n - 1, target)`).

The `main` function demonstrates how to use `countSubseq`. It initializes an array of integers, the size of the array, and a target sum. The function prints the number of valid subsequences whose sum equals the target.