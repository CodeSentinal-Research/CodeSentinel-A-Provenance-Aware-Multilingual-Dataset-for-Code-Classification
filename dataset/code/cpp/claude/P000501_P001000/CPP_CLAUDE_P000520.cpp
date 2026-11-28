#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const long long MOD=1e9+7;
int main(){int n;cin>>n;vector<long long>a(n);for(auto&v:a)cin>>v;
vector<long long>pre(n+1),pp(n+2);pre[0]=0;for(int i=0;i<n;i++)pre[i+1]=(pre[i]+a[i])%MOD;
pp[0]=0;for(int i=0;i<=n;i++)pp[i+1]=(pp[i]+pre[i+1])%MOD;
vector<int>left(n),right(n);stack<int>stk;
for(int i=0;i<n;i++){while(!stk.empty()&&a[stk.top()]>=a[i])stk.pop();left[i]=stk.empty()?-1:stk.top();stk.push(i);}
while(!stk.empty())stk.pop();
for(int i=n-1;i>=0;i--){while(!stk.empty()&&a[stk.top()]>a[i])stk.pop();right[i]=stk.empty()?n:stk.top();stk.push(i);}
long long ans=0;
for(int i=0;i<n;i++){int l=left[i]+1,r=right[i]-1;long long cl=i-l+1,cr=r-i;
long long tot=((pp[r+2]-pp[i+1]+MOD)%MOD*cl-(pp[i+1]-pp[l]+MOD)%MOD*cr%MOD+2*MOD)%MOD;
ans=(ans+a[i]%MOD*tot)%MOD;}cout<<ans<<"\n";}
