Here is the C++ code that implements the problem:

#include <iostream>
#include <vector>

using namespace std;

int countWindowsWithEvenSum(int n, int k, const vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < n - k + 1; ++i) {
        int sum = 0;
        for (int j = i; j < i + k; ++j) {
            sum += nums[j];
        }
        if (sum % 2 == 0) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << countWindowsWithEvenSum(n, k, nums);
    return 0;
}
This code first reads the size of the array and the window size. It then reads the array of integers. The countWindowsWithEvenSum function then iterates over the array, calculating the sum of the elements in each window of size k. If the sum is even, it increments the count. The main function handles the input and output.