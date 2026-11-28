Here's the code:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElementII(int nums[], int n) {
    unordered_map<int, int> count;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
    }

    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second > n / 3) {
            result.push_back(it->first);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = majorityElementII(nums, n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

This code first counts the occurrence of each number in the input array. Then it iterates over the map and checks if a number appears more than `n/3` times. If so, it adds the number to the result vector. The result vector is then printed to the console.