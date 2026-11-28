#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int matrix[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        cout << matrix[i][i] << " ";
    }
    for(int i = 0; i < N; i++) {
        cout << matrix[i][N-i-1] << " ";
    }
    return 0;
}