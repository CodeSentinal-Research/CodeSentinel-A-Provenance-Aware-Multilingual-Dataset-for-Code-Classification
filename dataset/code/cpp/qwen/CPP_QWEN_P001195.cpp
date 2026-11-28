#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<long long>add(n,0),sub(n,0);add[0]=a[0];for(int i=1;i<n;i++){add[i]=max(add[i-1],sub[i-1]+a[i]);sub[i]=max(sub[i-1],add[i-1]-a[i]);}cout<<max(add[n-1],sub[n-1])<<endl;return 0;}
