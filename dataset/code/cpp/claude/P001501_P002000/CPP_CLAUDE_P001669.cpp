#include <iostream>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int v):val(v),left(nullptr),right(nullptr){}};
class Solution{
public:
    TreeNode* insert(TreeNode* root,int v){if(!root)return new TreeNode(v);if(v<root->val)root->left=insert(root->left,v);else root->right=insert(root->right,v);return root;}
    void preorder(TreeNode* root){if(!root)return;cout<<root->val<<" ";preorder(root->left);preorder(root->right);}
};
int main(){
    int n;cin>>n;TreeNode*root=nullptr;Solution sol;
    for(int i=0;i<n;i++){int v;cin>>v;root=sol.insert(root,v);}
    sol.preorder(root);cout<<"\n";
}
