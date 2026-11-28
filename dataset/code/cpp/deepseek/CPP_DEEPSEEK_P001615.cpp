Sure, here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

int countSubmatrices(vector<vector<int>> &mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int count = 0;

    vector<vector<int>> prefixSum(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            prefixSum[i][j] = mat[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            for(int p=i; p<=n; p++) {
                for(int q=j; q<=m; q++) {
                    int sum = prefixSum[p][q] - prefixSum[p-i][q] - prefixSum[p][q-j] + prefixSum[p-i][q-j];
                    if(sum == target) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int N, M, Target;
    cin >> N >> M >> Target;

    vector<vector<int>> mat(N, vector<int>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> mat[i][j];
        }
    }

    int count = countSubmatrices(mat, Target);
    cout << count << "\n";

    return 0;
}
This code first calculates the prefix sum matrix to efficiently obtain the sum of the submatrices. Then, it traverses the prefix sum matrix to count the submatrices whose sum equals to the target. The time complexity of this code is O(N^3) due to the three nested loops.