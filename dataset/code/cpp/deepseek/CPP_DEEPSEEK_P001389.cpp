#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> map;
    int sum = 0, max_length = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            max_length = i + 1;
        } else {
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            } else {
                if (max_length < i - map[sum]) {
                    max_length = i - map[sum];
                }
            }
        }
    }

    cout << max_length << "\n";

    return 0;
}
This code first reads the size of the array and the array itself. Then, it iterates over the array and uses a running sum to find the longest subarray with equal number of 0s and 1s. It uses a hash map to store the running sum and its index, and updates the maximum length if a sum has been seen before.