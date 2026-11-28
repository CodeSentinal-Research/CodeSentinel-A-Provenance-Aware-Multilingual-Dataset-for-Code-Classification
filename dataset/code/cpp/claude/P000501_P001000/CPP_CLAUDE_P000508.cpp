#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){int n;cin>>n;vector<int>h(n),ans(n);stack<int>stk;
for(auto&v:h)cin>>v;
for(int i=n-1;i>=0;i--){int cnt=0;
    while(!stk.empty()&&stk.top()<h[i]){stk.pop();cnt++;}
    if(!stk.empty())cnt++;ans[i]=cnt;stk.push(h[i]);}
for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];}
