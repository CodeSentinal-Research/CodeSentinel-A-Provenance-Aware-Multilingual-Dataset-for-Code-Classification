#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int l=0,r=n-1;while(l<r){int s=a[l]+a[r];if(s==t){cout<<l+1<<" "<<r+1<<endl;return 0;}else if(s<t)l++;else r--;}return 0;}
