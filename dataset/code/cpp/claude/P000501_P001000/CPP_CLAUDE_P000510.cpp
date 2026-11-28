#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){int n;cin>>n;vector<int>p(n);for(auto&v:p)cin>>v;vector<int>res(p);stack<int>stk;
for(int i=0;i<n;i++){while(!stk.empty()&&p[stk.top()]>=p[i]){res[stk.top()]-=p[i];stk.pop();}stk.push(i);}
for(int i=0;i<n;i++)cout<<res[i]<<" \n"[i==n-1];}
