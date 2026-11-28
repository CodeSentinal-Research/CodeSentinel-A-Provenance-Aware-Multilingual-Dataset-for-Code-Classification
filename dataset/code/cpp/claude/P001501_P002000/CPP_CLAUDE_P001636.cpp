#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode{int val;TreeNode*left,*right;TreeNode(int v):val(v),left(nullptr),right(nullptr){}};
class Solution{
public:
    TreeNode* insert(TreeNode* root,int v){if(!root)return new TreeNode(v);if(v<root->val)root->left=insert(root->left,v);else root->right=insert(root->right,v);return root;}
    int height(TreeNode* root){if(!root)return 0;return 1+max(height(root->left),height(root->right));}
};
int main(){
    int n;cin>>n;TreeNode*root=nullptr;Solution sol;
    for(int i=0;i<n;i++){int v;cin>>v;root=sol.insert(root,v);}
    cout<<sol.height(root)<<"\n";
}
