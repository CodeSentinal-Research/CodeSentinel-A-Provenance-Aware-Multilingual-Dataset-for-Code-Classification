#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ThreadedNode {
    int val;
    ThreadedNode *left;
    ThreadedNode *right;
    bool isThreaded;
    ThreadedNode(int x) : val(x), left(NULL), right(NULL), isThreaded(false) {}
};

ThreadedNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return NULL;
    ThreadedNode* root = new ThreadedNode(vals[0]);
    queue<ThreadedNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        ThreadedNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new ThreadedNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new ThreadedNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void convertToThreaded(ThreadedNode* root, ThreadedNode*& prev) {
    if (!root) return;
    
    convertToThreaded(root->left, prev);
    
    if (prev && !root->left) {
        // Not standard threading, usually right pointer is threaded
    }
    if (prev && !prev->right) {
        prev->right = root;
        prev->isThreaded = true;
    }
    
    prev = root;
    convertToThreaded(root->right, prev);
}

void printInorder(ThreadedNode* root) {
    ThreadedNode* curr = root;
    while (curr) {
        while (curr->left) curr = curr->left;
        cout << curr->val << " ";
        while (curr->isThreaded && curr->right) {
            curr = curr->right;
            cout << curr->val << " ";
        }
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    
    ThreadedNode* root = buildTree(vals);
    ThreadedNode* prev = NULL;
    convertToThreaded(root, prev);
    
    printInorder(root);
    
    return 0;
}
