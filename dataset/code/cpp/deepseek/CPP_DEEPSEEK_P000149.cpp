#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxRow = 0;
    int maxCount = 0;

    for(int i = 0; i < rows; i++) {
        int count = 0;
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1) {
                count++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            maxRow = i;
        }
    }

    cout << maxRow;

    return 0;
}