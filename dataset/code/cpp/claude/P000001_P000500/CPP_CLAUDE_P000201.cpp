#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSumIncreasingSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(arr);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
        return *max_element(dp.begin(), dp.end());
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    cout << Solution().maxSumIncreasingSubseq(arr) << "\n";
}
