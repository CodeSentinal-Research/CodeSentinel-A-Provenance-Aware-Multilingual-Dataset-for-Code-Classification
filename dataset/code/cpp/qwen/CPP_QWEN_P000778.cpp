#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

void tugOfWar(vector<int>& nums, int index, vector<int>& set1, vector<int>& set2, int sum1, int sum2, int& minDiff) {
    if (index == nums.size()) {
        int diff = abs(sum1 - sum2);
        if (diff < minDiff) minDiff = diff;
        return;
    }
    
    set1.push_back(nums[index]);
    tugOfWar(nums, index + 1, set1, set2, sum1 + nums[index], sum2, minDiff);
    set1.pop_back();
    
    set2.push_back(nums[index]);
    tugOfWar(nums, index + 1, set1, set2, sum1, sum2 + nums[index], minDiff);
    set2.pop_back();
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    
    vector<int> set1, set2;
    int minDiff = INT_MAX;
    tugOfWar(nums, 0, set1, set2, 0, 0, minDiff);
    cout << minDiff << endl;
    return 0;
}
