#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rowIndex;
    cin >> rowIndex;
    vector<long long> row(rowIndex + 1, 1);
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i - 1; j > 0; --j) {
            row[j] += row[j-1];
        }
    }
    
    for (size_t i = 0; i < row.size(); ++i) {
        if (i > 0) cout << " ";
        cout << row[i];
    }
    cout << endl;
    return 0;
}
