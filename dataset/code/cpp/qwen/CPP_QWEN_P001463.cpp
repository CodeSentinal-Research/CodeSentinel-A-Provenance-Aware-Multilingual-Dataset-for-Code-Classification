#include<bits/stdc++.h>
using namespace std;
int main(){int n,v;cin>>n>>v;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int j=0;for(int i=0;i<n;i++)if(a[i]!=v)a[j++]=a[i];cout<<j<<endl;for(int i=0;i<j;i++)cout<<a[i]<<" ";cout<<endl;return 0;}
