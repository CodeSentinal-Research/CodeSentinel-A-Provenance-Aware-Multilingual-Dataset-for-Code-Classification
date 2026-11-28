#include<bits/stdc++.h>
using namespace std;
int main(){int n,fee;cin>>n>>fee;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];long long s=-a[0],h=0;for(int i=1;i<n;i++){long long ns=max(s,h-a[i]);long long nh=max(h,s+a[i]-fee);s=ns;h=nh;}cout<<h<<endl;return 0;}
