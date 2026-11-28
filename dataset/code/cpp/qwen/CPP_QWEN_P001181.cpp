#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int mx=0;for(int i=0;i<n;i++){if(a[i]==0){cout<<"NO"<<endl;return 0;}mx=max(mx,i+a[i]);if(mx>=n-1){cout<<"YES"<<endl;return 0;}}cout<<"NO"<<endl;return 0;}
