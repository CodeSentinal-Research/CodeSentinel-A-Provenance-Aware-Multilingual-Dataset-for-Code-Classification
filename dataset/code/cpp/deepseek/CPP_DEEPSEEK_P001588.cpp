Here is a simple C++ solution for the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int count = 0;
    for (int start = 0; start < N; start++) {
        int oddCount = 0;
        for (int end = start; end < N; end++) {
            if (nums[end] % 2 == 1) {
                oddCount++;
            }
            if (oddCount == K) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

This code first reads the size of the array and the number of odd numbers to be counted. It then reads the array of integers. For each start position, it iterates through the rest of the array to count the number of odd numbers starting at that position. If it finds K consecutive odd numbers, it increments the count. The final count is printed out.