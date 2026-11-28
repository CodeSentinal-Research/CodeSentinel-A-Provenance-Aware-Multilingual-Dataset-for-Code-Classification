#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> map;
    int maxLen = 0, sum = 0;

    for(int j = 0; j < n; j++) {
        sum += nums[j];
        if(sum == k) {
            maxLen = max(maxLen, j+1);
        }
        if(map.find(sum - k) != map.end()) {
            if(maxLen < j - map[sum - k]) {
                maxLen = j - map[sum - k];
            }
        }
        if(map.find(sum) == map.end()) {
            map[sum] = j;
        }
    }

    cout << maxLen;
    return 0;
}