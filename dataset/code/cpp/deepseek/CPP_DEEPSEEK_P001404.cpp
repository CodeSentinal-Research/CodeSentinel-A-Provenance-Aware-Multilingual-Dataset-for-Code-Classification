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

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            if(matrix[i][j] == matrix[j][i]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}