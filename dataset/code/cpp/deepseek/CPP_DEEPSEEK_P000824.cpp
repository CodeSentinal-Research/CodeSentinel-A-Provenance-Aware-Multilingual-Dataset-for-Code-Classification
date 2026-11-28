#include <iostream>
using namespace std;

bool searchMatrix(int N, int M, int matrix[N][M], int target) {
    if (N == 0 || M == 0)
        return false;
    
    int left = 0;
    int right = N * M - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / M][mid % M];
        
        if (midValue == target)
            return true;
        else if (midValue < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int target;
    cin >> target;
    
    if (searchMatrix(N, M, matrix, target))
        cout << "true";
    else
        cout << "false";
    
    return 0;
}