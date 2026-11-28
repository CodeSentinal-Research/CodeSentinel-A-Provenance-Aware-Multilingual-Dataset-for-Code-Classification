#include <iostream>
using namespace std;

int countUniquePaths(int m, int n) {
    int uniquePaths[m][n];

    for(int i = 0; i < m; i++) {
        uniquePaths[i][0] = 1;
    }
    for(int j = 0; j < n; j++) {
        uniquePaths[0][j] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            uniquePaths[i][j] = uniquePaths[i-1][j] + uniquePaths[i][j-1];
        }
    }

    return uniquePaths[m-1][n-1];
}

int main() {
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    if(m < 1 || n < 1 || m > 100 || n > 100) {
        cout << "Invalid input. m and n should be between 1 and 100.";
        return 0;
    }

    cout << "Number of unique paths: " << countUniquePaths(m, n);
    return 0;
}