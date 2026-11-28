#include<iostream>
#include<vector>
#include<stack>
using namespace std;
long long hist(vector<int>h){h.push_back(0);stack<int>stk;long long mx=0;for(int i=0;i<(int)h.size();i++){while(!stk.empty()&&h[stk.top()]>h[i]){int ht=h[stk.top()];stk.pop();int w=stk.empty()?i:i-stk.top()-1;mx=max(mx,(long long)ht*w);}stk.push(i);}return mx;}
int main(){int r,c;cin>>r>>c;vector<int>h(c,0);long long ans=0;for(int i=0;i<r;i++){string row;for(int j=0;j<c;j++){cin>>row;h[j]=row[0]=='1'?h[j]+1:0;}ans=max(ans,hist(h));}cout<<ans<<"\n";}
