Here is the C++ code for the problem:

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int getMaxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    int res = INT_MIN;
    
    for (int l = 0; l < m; ++l) {
        vector<int> temp(n, 0);
        for (int r = l; r < m; ++r) {
            for (int i = 0; i < n; ++i)
                temp[i] += matrix[i][r];
            
            set<int> s;
            s.insert(0);
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                cur += temp[i];
                auto it = s.lower_bound(cur - k);
                if (it != s.end())
                    res = max(res, cur - *it);
                s.insert(cur);
            }
       
            if (res == k)
                return res;
        }
    }
    return res;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matrix[i][j];
            
    cout << getMaxSumSubmatrix(matrix, K);
    
    return 0;
}

This C++ program uses a variation of Kadane's algorithm to find the maximum sum of a submatrix in a given matrix, and the set to track the running sums, up to a limit K. The main difference from the standard version of Kadane's algorithm is that we use a set (s) instead of a vector to track the running sums, and the insert and lower_bound functions. The res variable is used to store the maximum sum that is not larger than K. The time complexity is O(n^2m^2) in the worst case.