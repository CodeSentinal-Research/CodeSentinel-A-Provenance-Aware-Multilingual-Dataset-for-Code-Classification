#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };
bool dfs(ListNode* head, TreeNode* root) {
    if(!head) return true; if(!root) return false; if(root->val != head->val) return false;
    return dfs(head->next, root->left) || dfs(head->next, root->right);
}
int main() {
    int n; cin >> n; vector<int> vals(n); for(int i=0; i<n; i++) cin >> vals[i];
    ListNode* head = nullptr; ListNode* curr = nullptr;
    for(int i=0; i<n; i++) { if(!head) { head = new ListNode(vals[i]); curr = head; } else { curr->next = new ListNode(vals[i]); curr = curr->next; } }
    int m; cin >> m; vector<int> tvals(m); for(int i=0; i<m; i++) cin >> tvals[i];
    TreeNode* root = nullptr; queue<TreeNode*> q;
    if(m > 0 && tvals[0] != -1) { root = new TreeNode(tvals[0]); q.push(root); int idx = 1;
        while(!q.empty() && idx < m) { TreeNode* node = q.front(); q.pop();
            if(idx < m && tvals[idx] != -1) { node->left = new TreeNode(tvals[idx]); q.push(node->left); } idx++;
            if(idx < m && tvals[idx] != -1) { node->right = new TreeNode(tvals[idx]); q.push(node->right); } idx++;
        }
    }
    bool found = false; queue<TreeNode*> bfs; if(root) bfs.push(root);
    while(!bfs.empty()) { TreeNode* node = bfs.front(); bfs.pop(); if(dfs(head, node)) { found = true; break; } if(node->left) bfs.push(node->left); if(node->right) bfs.push(node->right); }
    cout << (found ? "true" : "false") << endl; return 0;
}
