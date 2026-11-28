#include <iostream>
#include <vector>
using namespace std;

bool checkArithmeticSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
    for (auto& query : queries) {
        int L = query[0], R = query[1];
        if (R - L + 1 < 2) continue; 
        int diff = nums[L] - nums[L + 1];
        for (int i = L + 2; i <= R; i++) {
            if ((nums[i] - nums[i - 1]) != diff) {
                goto not_arithmetic;
            }
        }
        cout << "YES" << endl;
        continue;
        not_arithmetic:
        cout << "NO" << endl;
    }
    return true;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> queries(Q, vector<int>(2));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }
    }
    checkArithmeticSubarrays(nums, queries);
    return 0;
}