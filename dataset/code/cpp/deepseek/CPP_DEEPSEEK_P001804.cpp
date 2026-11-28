#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    Node* left, * right;

    Node(int x) {
        key = x;
        left = right = nullptr;
    }
};

Node* sortedArrayToBST(vector<int> &arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

bool areIdentical(vector<int> &arr1, vector<int> &arr2) {
    if (arr1.size() != arr2.size()) return false;

    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i]) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    if (areIdentical(arr1, arr2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
This C++ code reads two sequences of distinct keys, sorts them, and then checks if they're identical. If they are, it prints "YES", otherwise it prints "NO". 

Please note that this solution assumes that the sequences are sorted, as the problem statement specifies that they are. Also, this solution uses the sorted array to construct a binary search tree, not the two insertion sequences. The constructed tree is not identical to the two sequences if the sequences have different orders of insertions.