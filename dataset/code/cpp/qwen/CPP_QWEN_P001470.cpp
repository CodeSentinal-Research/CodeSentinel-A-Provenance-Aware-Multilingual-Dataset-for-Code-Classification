#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<int>a(n),b(m);for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<m;i++)cin>>b[i];int i=0,j=0;while(i<n&&j<m){if(a[i]>b[j]){swap(a[i],b[j]);sort(b.begin(),b.begin()+m);}i++;}for(int x:a)cout<<x<<" ";cout<<"\n";for(int x:b)cout<<x<<" ";cout<<endl;return 0;}
