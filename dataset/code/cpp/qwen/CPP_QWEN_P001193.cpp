#include<bits/stdc++.h>
using namespace std;
struct TreeNode{int val;TreeNode*left;TreeNode*right;};
pair<long long,long long>dfs(TreeNode*root){if(!root)return {0,0};auto l=dfs(root->left);auto r=dfs(root->right);long long inc=root->val+l.first+r.first;long long exc=max(l.first,l.second)+max(r.first,r.second);return {inc,exc};}
int main(){int n;cin>>n;vector<TreeNode*>nodes(n);for(int i=0;i<n;i++)nodes[i]=new TreeNode();for(int i=0;i<n;i++){int l,r;cin>>nodes[i]->val>>l>>r;if(l!=-1)nodes[i]->left=nodes[l];if(r!=-1)nodes[i]->right=nodes[r];}auto res=dfs(nodes[0]);cout<<max(res.first,res.second)<<endl;return 0;}
