#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &preorder, int start, int end) {
    if (start >= end) {
        return true;
    }

    int root = preorder[start];
    int i = start + 1;

    while (i <= end && preorder[i] < root) {
        i++;
    }

    while (i <= end && preorder[i] > root) {
        if (preorder[i] < root) {
            return false;
        }
        i++;
    }

    return isValid(preorder, start + 1, i - 1) && isValid(preorder, i, end);
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    if (isValid(preorder, 0, n - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
This C++ program reads the preorder traversal sequence from the standard input, validates it using a recursive helper function `isValid()`, and prints "YES" if the sequence can represent a Binary Search Tree and "NO" otherwise.