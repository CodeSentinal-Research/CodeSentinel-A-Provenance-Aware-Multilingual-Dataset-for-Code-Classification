#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<vector<int>> matrix(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    bool hasSaddlePoint = false;

    for(int i = 0; i < N; i++) {
        int minRow = matrix[i][0];
        int maxCol = matrix[0][i];

        for(int j = 0; j < N; j++) {
            if(matrix[i][j] < minRow) {
                minRow = matrix[i][j];
            }
            if(matrix[i][j] > maxCol) {
                maxCol = matrix[i][j];
            }
        }

        if(minRow == maxCol) {
            cout << minRow << " ";
            hasSaddlePoint = true;
            break;
        }
    }

    if(!hasSaddlePoint) {
        cout << "No Saddle Point";
    }

    return 0;
}