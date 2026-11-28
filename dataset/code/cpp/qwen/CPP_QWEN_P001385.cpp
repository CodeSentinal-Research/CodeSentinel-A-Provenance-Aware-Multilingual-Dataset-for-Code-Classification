#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int mn=a[0],idx=0;for(int i=1;i<n;i++)if(a[i]<mn){mn=a[i];idx=i;}cout<<idx<<endl;return 0;}
