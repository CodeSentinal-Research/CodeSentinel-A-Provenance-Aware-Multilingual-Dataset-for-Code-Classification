#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    vector<int> dp(N, 1);
    vector<int> parent(N, -1);
    int maxIdx = 0;
    
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[maxIdx]) maxIdx = i;
    }
    
    vector<int> result;
    int curr = maxIdx;
    while (curr != -1) {
        result.push_back(nums[curr]);
        curr = parent[curr];
    }
    reverse(result.begin(), result.end());
    
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    return 0;
}
