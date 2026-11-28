#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const long long MOD=1e9+7;
int main(){int n;cin>>n;vector<long long>a(n+1);for(int i=0;i<n;i++)cin>>a[i];a[n]=-1;stack<int>stk;long long res=0;for(int i=0;i<=n;i++){while(!stk.empty()&&a[stk.top()]>=a[i]){int mid=stk.top();stk.pop();int left=stk.empty()?-1:stk.top();res=(res+a[mid]*(mid-left)*(i-mid))%MOD;}stk.push(i);}cout<<res<<"\n";}
