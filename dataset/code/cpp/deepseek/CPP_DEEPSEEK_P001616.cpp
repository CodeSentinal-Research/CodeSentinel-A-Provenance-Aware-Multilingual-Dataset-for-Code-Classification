#include <iostream>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;

    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int sum = 0;
        for (int j = c1; j <= c2; j++) {
            sum += matrix[r1][j];
        }

        for (int i = r1+1; i <= r2; i++) {
            sum += matrix[i][c2];
        }

        cout << sum << endl;
    }

    return 0;
}