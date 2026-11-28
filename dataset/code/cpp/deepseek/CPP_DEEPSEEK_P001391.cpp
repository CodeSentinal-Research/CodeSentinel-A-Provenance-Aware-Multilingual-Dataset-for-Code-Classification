Here is the code snippet:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> prefixSums;
    int sum = 0, count = 0;
    prefixSums[0] = 1;

    for(int num : nums) {
        sum += num;
        if(prefixSums.find(sum - K) != prefixSums.end()) {
            count += prefixSums[sum - K];
        }
        prefixSums[sum]++;
    }

    cout << count << endl;

    return 0;
}

This code reads an array of integers and a target sum K. It uses a hash map (unordered_map) to store the prefix sums of the array and counts the number of subarrays with a sum equal to K.