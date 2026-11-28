Here is the C++ code:

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int count = 0;
    for(int start = 0; start < n; start++) {
        int oddCount = 0;
        for(int end = start; end < n; end++) {
            if(nums[end] % 2 != 0) {
                oddCount++;
            }
            if(oddCount == k) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

This program first reads the size of the array and the number of odd numbers to count from the standard input. It then reads the array of numbers. It then iterates through each possible starting point for the subarray and for each starting point, it iterates through the rest of the array. If it encounters an odd number, it increments the odd number count. If the odd number count equals the number of odd numbers to count, it increments the count of valid subarrays. Finally, it prints the count of valid subarrays.