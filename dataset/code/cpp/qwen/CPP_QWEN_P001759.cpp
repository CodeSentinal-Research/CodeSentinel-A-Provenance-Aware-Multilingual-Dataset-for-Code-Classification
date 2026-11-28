#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return NULL;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void findModes(TreeNode* root, unordered_map<int, int>& freq, int& maxFreq) {
    if (!root) return;
    freq[root->val]++;
    maxFreq = max(maxFreq, freq[root->val]);
    findModes(root->left, freq, maxFreq);
    findModes(root->right, freq, maxFreq);
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    TreeNode* root = buildTree(vals);
    unordered_map<int, int> freq;
    int maxFreq = 0;
    findModes(root, freq, maxFreq);
    
    vector<int> modes;
    for (auto& p : freq) {
        if (p.second == maxFreq) {
            modes.push_back(p.first);
        }
    }
    sort(modes.begin(), modes.end());
    
    for (int m : modes) {
        cout << m << " ";
    }
    cout << endl;
    
    return 0;
}
