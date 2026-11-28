Here is the C++ code with the required #include and using namespace statements.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> count;
    int res = 0;
    for (int num : nums) {
        if (count.find(num ^ K) != count.end()) {
            res += count[num ^ K];
        }
        ++count[num];
    }

    cout << res << endl;
    return 0;
}

This code first reads the size of the array and the XOR value K. Then it reads the array of numbers. It creates an unordered map to count the number of occurrences of each number. It then iterates over the array, and for each number, it checks if the XOR of the number with K has already been counted. If it has, it adds the count from the map to the result. Finally, it increments the count of the current number in the map.