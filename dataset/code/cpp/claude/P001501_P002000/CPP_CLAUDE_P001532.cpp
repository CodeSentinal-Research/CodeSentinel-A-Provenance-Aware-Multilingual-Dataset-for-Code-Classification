#include <iostream>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int v):val(v),left(nullptr),right(nullptr){}};
class Solution{
public:
    TreeNode* insert(TreeNode* root,int v){if(!root)return new TreeNode(v);if(v<root->val)root->left=insert(root->left,v);else if(v>root->val)root->right=insert(root->right,v);return root;}
    TreeNode* search(TreeNode* root,int k){if(!root||root->val==k)return root;if(k<root->val)return search(root->left,k);return search(root->right,k);}
    void inorder(TreeNode* root){if(!root)return;inorder(root->left);cout<<root->val<<" ";inorder(root->right);}
};
int main(){
    int n;cin>>n;TreeNode*root=nullptr;Solution sol;
    for(int i=0;i<n;i++){int v;cin>>v;root=sol.insert(root,v);}
    int k;cin>>k;
    cout<<(sol.search(root,k)?"Found":"Not Found")<<"\n";
    sol.inorder(root);cout<<"\n";
}
