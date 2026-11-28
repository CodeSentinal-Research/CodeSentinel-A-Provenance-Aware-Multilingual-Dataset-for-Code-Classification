#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int m = matrix.size(), n = matrix[0].size();
    int maxArea = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i && matrix[i][j] && matrix[i-1][j]) {
                matrix[i][j] += matrix[i-1][j];
            }

            for (int p = i; p < m; ++p) {
                int width = p - i + 1;
                int area = width * matrix[p][j];
                maxArea = max(maxArea, area);

                if (matrix[p][j] == 0) {
                    break;
                }
            }

            for (int q = j; q < n; ++q) {
                int height = q - j + 1;
                int area = height * matrix[i][q];
                maxArea = max(maxArea, area);

                if (matrix[i][q] == 0) {
                    break;
                }
            }
        }
    }

    return maxArea;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (auto& row : matrix) {
        for (auto& elem : row) {
            cin >> elem;
        }
    }

    cout << maxArea(matrix) << endl;

    return 0;
}