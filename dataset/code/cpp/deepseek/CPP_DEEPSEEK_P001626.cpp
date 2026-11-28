Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, M, Threshold;
    cin >> N >> M >> Threshold;

    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxSideLength = 0;
    for (int s = min(N, M); s > 0; s--) {
        for (int i = 0; i <= N - s; i++) {
            for (int j = 0; j <= M - s; j++) {
                int sum = matrix[i+s-1][j+s-1] - (s > 0 ? matrix[i+s-1][j] + matrix[i][j+s-1] - matrix[i][j] : 0);
                if (sum < Threshold && s > maxSideLength) {
                    maxSideLength = s;
                }
            }
        }
    }

    cout << maxSideLength << endl;

    return 0;
}

This code first reads the matrix and the threshold. Then it calculates the sum of the square and compares it with the threshold. If the sum is less than the threshold and the size of the square is greater than the previous maximum, it updates the maximum size. This process is repeated for all possible square sizes starting from the minimum of N and M. The maximum size of the square with a sum less than the threshold is then printed.