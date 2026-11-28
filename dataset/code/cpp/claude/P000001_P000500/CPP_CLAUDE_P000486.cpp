#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){int n;cin>>n;vector<int>h(n+1);for(int i=0;i<n;i++)cin>>h[i];h[n]=0;stack<int>stk;long long mx=0;for(int i=0;i<=n;i++){while(!stk.empty()&&h[stk.top()]>h[i]){int ht=h[stk.top()];stk.pop();int w=stk.empty()?i:i-stk.top()-1;mx=max(mx,(long long)ht*w);}stk.push(i);}cout<<mx<<"\n";}
