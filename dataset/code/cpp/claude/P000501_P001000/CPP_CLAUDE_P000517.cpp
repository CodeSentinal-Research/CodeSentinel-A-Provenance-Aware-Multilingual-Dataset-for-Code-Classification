#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){int n;cin>>n;vector<int>t(n),ans(n,0);for(auto&v:t)cin>>v;stack<int>stk;
for(int i=0;i<n;i++){while(!stk.empty()&&t[stk.top()]<t[i]){int j=stk.top();stk.pop();ans[j]=i-j;}stk.push(i);}
for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];}
