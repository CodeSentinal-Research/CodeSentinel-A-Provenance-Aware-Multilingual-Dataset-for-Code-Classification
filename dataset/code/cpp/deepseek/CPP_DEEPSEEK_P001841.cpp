Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

void inorder(TreeNode* node, vector<int>& res) {
    if (node == NULL) return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}

int main() {
    int N1, N2;
    cin >> N1;
    vector<int> res1;
    for (int i = 0; i < N1; i++) {
        int val;
        cin >> val;
        res1.push_back(val);
    }
    cin >> N2;
    vector<int> res2;
    for (int i = 0; i < N2; i++) {
        int val;
        cin >> val;
        res2.push_back(val);
    }
    res1.erase(unique(res1.begin(), res1.end()), res1.end());
    res2.erase(unique(res2.begin(), res2.end()), res2.end());
    vector<int> res;
    set_intersection(res1.begin(), res1.end(), res2.begin(), res2.end(), back_inserter(res));
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}

This code reads two binary search trees from the input, then finds the intersection of the two BSTs. The intersection is then sorted and printed. The `set_intersection` algorithm from the Standard Library is used to find the common elements in the two BSTs. The `sort` function is used to sort the result.