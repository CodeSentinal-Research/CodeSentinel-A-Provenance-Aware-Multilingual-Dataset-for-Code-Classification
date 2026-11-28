#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> binaryValues(N);
    for (int i = 0; i < N; i++) {
        cin >> binaryValues[i];
    }

    vector<vector<int>> binaryTree(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> binaryTree[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        int num = binaryValues[i];
        for (int j = i; j >= 0; j--) {
            num = num * 2 + binaryTree[j][i - j];
        }
        sum += num;
    }

    cout << sum << endl;

    return 0;
}