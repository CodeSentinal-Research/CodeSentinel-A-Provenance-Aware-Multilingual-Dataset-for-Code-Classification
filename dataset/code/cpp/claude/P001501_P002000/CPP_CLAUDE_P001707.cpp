#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int v):val(v),left(nullptr),right(nullptr){}};
class Solution{
public:
    TreeNode* insert(TreeNode* root,int v){if(!root)return new TreeNode(v);if(v<root->val)root->left=insert(root->left,v);else root->right=insert(root->right,v);return root;}
    void levelOrder(TreeNode* root){
        if(!root)return;
        queue<TreeNode*> q;q.push(root);
        while(!q.empty()){auto cur=q.front();q.pop();cout<<cur->val<<" ";if(cur->left)q.push(cur->left);if(cur->right)q.push(cur->right);}
        cout<<"\n";
    }
};
int main(){
    int n;cin>>n;TreeNode*root=nullptr;Solution sol;
    for(int i=0;i<n;i++){int v;cin>>v;root=sol.insert(root,v);}
    sol.levelOrder(root);
}
