#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols, target;
    cin >> rows >> cols >> target;

    for (int i = 0; i < rows; i++) {
        vector<int> row(cols);
        for (int j = 0; j < cols; j++) {
            cin >> row[j];
        }

        if (row[0] > target) {
            cout << "Not Found\n";
            return 0;
        }

        for (int j = 0; j < cols - 1; j++) {
            if (row[j + 1] > target) {
                cout << "Found\n";
                return 0;
            }
        }
    }

    cout << "Not Found\n";
    return 0;
}