#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numRows;
    cin >> numRows;
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    
    for (const auto& row : triangle) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) cout << " ";
            cout << row[i];
        }
        cout << endl;
    }
    return 0;
}
