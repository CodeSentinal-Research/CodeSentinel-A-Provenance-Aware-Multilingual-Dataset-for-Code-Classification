#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, target;
    cin >> N >> M >> target;
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matrix[i][j];

    int r = 0, c = M - 1;
    bool found = false;
    while (r < N && c >= 0) {
        if (matrix[r][c] == target) {
            found = true;
            break;
        } else if (matrix[r][c] > target) {
            c--;
        } else {
            r++;
        }
    }
    cout << (found ? "true" : "false") << endl;
    return 0;
}
