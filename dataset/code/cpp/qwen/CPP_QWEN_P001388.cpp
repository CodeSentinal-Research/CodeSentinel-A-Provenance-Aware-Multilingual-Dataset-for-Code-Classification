#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<string>a(n);for(int i=0;i<n;i++)cin>>a[i];int mx=0,idx=0;for(int i=0;i<n;i++)if(a[i].size()>mx){mx=a[i].size();idx=i;}cout<<idx<<endl;return 0;}
