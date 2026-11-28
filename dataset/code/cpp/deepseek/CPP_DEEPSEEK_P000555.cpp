Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minReverseOperations(int n, int p, vector<int> banned, int k) {
    vector<int> operations(n, -1);
    operations[p] = 0;

    for (int i = max(0, p - k + 1); i <= min(p, n - k); i++) {
        if (find(banned.begin(), banned.end(), i) == banned.end()) {
            operations[i] = operations[i + 1] + 1;
        }
    }

    for (int i = min(p, n - k); i >= k; i--) {
        if (find(banned.begin(), banned.end(), i) == banned.end()) {
            operations[i] = operations[i - 1] + 1;
        }
    }

    return operations;
}

int main() {
    int n, p;
    vector<int> banned;
    int k;

    cin >> n >> p;

    banned.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> banned[i];
    }

    cin >> k;

    vector<int> result = minReverseOperations(n, p, banned, k);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}

This code will read the input from the standard input, call the `minReverseOperations` function with the input, and then print the result to the standard output. The `minReverseOperations` function implements the logic of the problem. It iterates over the array from both ends of the token and keeps track of the minimum operations to reach each index. If an index is banned, it sets the operation to -1.