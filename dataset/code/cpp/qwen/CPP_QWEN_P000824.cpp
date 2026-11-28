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

    int low = 0, high = N * M - 1;
    bool found = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int val = matrix[mid / M][mid % M];
        if (val == target) {
            found = true;
            break;
        } else if (val < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << (found ? "true" : "false") << endl;
    return 0;
}
