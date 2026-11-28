#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                cout << "Not Symmetric";
                return 0;
            }
        }
    }

    cout << "Symmetric";
    return 0;
}