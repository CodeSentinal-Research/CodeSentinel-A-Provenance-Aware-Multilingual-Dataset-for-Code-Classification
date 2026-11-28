Here is the code:

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minSumPath(int N, vector<vector<int>> matrix) {
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            if(j>0)
                matrix[i][j]+=min(matrix[i-1][j-1],matrix[i-1][j]);
            else
                matrix[i][j]+=matrix[i-1][j];

            if(j<N-1)
                matrix[i][j]+=min(matrix[i-1][j+1],matrix[i-1][j]);
        }
    }

    int minSum=INT_MAX;
    for(int i=0;i<N;i++)
        minSum=min(minSum,matrix[N-1][i]);

    return minSum;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << minSumPath(N, matrix);

    return 0;
}

In this code, we're using the dynamic programming approach. We first calculate the minimum sum of each cell in the bottom row, then we update the minimum sum of each cell in the second bottom row. Finally, we find the minimum sum in the last row.

This algorithm has a time complexity of O(N^2) and a space complexity of O(N^2).