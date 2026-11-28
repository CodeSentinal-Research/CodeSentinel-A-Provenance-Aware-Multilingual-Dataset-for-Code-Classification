#include <iostream>
using namespace std;

void constructPrefixSumMatrix(int N, int M, int grid[N][M]) {
    int prefixSumMatrix[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            prefixSumMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i > 0) prefixSumMatrix[i][j] += prefixSumMatrix[i-1][j];
            if(j > 0) prefixSumMatrix[i][j] += prefixSumMatrix[i][j-1];
            if(i > 0 && j > 0) prefixSumMatrix[i][j] -= prefixSumMatrix[i-1][j-1];
            prefixSumMatrix[i][j] += grid[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << prefixSumMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int grid[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    constructPrefixSumMatrix(N, M, grid);

    return 0;
}
This program will prompt the user to input the dimensions N and M for the 2D matrix, then the actual matrix values. The prefix sum matrix is then constructed and printed.