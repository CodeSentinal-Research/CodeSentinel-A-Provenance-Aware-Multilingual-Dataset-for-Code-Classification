Here is the code for the given problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int total = N * N;
    int constraint_count;
    cin >> constraint_count;

    if (constraint_count > total || constraint_count < total) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int matrix[N][N];
    bool col[N] = {0};
    bool dia_l[N] = {0};
    bool dia_r[N] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int current_constraint = constraint_count - total;
            cin >> matrix[i][j];

            if (matrix[i][j] > total || matrix[i][j] < 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }

            if (matrix[i][j] != 0 && col[matrix[i][j] - 1] == true) {
                cout << "IMPOSSIBLE";
                return 0;
            }

            if (i - j != 0 && matrix[i][j] - 1 != current_constraint && dia_l[i - j] == true && dia_r[i + j] == true) {
                cout << "IMPOSSIBLE";
                return 0;
            }

            if (matrix[i][j] - 1 != current_constraint && dia_l[i - j] == false) {
                dia_l[i - j] = true;
            }

            if (matrix[i][j] - 1 != current_constraint && dia_r[i + j] == false) {
                dia_r[i + j] = true;
            }

            if (matrix[i][j] - 1 != current_constraint && col[matrix[i][j] - 1] == false) {
                col[matrix[i][j] - 1] = true;
            }

            current_constraint++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
This program reads the size of the matrix N, the number of constraints M, and then reads the constraints. It then checks if the constraints are valid and if they are, it fills the matrix. If the constraints are not valid, it outputs "IMPOSSIBLE".