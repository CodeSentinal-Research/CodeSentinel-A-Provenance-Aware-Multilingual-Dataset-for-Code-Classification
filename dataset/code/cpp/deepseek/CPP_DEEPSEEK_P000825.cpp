Here is the C++ code to solve the problem:

#include <iostream>
using namespace std;

bool searchMatrix(int N, int M, int target, int matrix[N][M]) {
    if (N == 0 || M == 0) return false;

    int row = 0;
    int col = M - 1;

    while (row < N && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    int matrix[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    int target;
    cin >> target;

    if (searchMatrix(N, M, target, matrix))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

In this code, we start from the bottom right corner of the matrix and compare the target with the current element. If it's greater, we move upwards, otherwise, we move to the left. This way, we find the target within the matrix in O(N + M) time, which is more efficient than the O(N*M) time complexity.