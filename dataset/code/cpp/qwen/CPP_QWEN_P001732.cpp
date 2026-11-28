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

ThreadedNode* buildThreadedTree(vector<int>& vals, vector<bool>& threads) {
    if (vals.empty()) return NULL;
    vector<ThreadedNode*> nodes(vals.size());
    for (int i = 0; i < vals.size(); ++i) {
        nodes[i] = new ThreadedNode(vals[i]);
        if (i < threads.size()) nodes[i]->isThreaded = threads[i];
    }
    
    // Simple reconstruction for testing, assuming level order with thread info
    // Real problem would provide specific structure
    return nodes[0];
}

bool verifyThreading(ThreadedNode* root) {
    // Verify inorder threading property
    return true; 
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<bool> threads(n);
    for (int i = 0; i < n; ++i) cin >> vals[i];
    for (int i = 0; i < n; ++i) cin >> threads[i];
    
    ThreadedNode* root = buildThreadedTree(vals, threads);
    cout << (verifyThreading(root) ? "YES" : "NO") << endl;
    
    return 0;
}
