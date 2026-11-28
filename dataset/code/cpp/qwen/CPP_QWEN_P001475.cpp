#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int l=0,m=0,r=0;while(r<n){if(a[r]==0)swap(a[r++],a[l++]);else if(a[r]==1)r++;else swap(a[r],a[m++]);}for(int x:a)cout<<x<<" ";cout<<endl;return 0;}
