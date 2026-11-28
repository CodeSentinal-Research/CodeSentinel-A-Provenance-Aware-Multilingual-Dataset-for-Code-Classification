#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> firstRow = matrix[0];

    for (int i = 1; i < rows; i++) {
        vector<int> currentRow = matrix[i];
        vector<int> commonElements;

        set_intersection(firstRow.begin(), firstRow.end(), currentRow.begin(), currentRow.end(),
                         back_inserter(commonElements));

        cout << "Common elements in row " << (i+1) << ": ";
        for (int element : commonElements) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}