#include<bits/stdc++.h>
using namespace std;
int main(){int n,p;cin>>n>>p;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];sort(a.begin(),a.end());int l=0,r=n-1,res=0;while(l<=r){if(p>=a[l]){p-=a[l];l++;res++;}else if(res>0){p+=a[r];r--;res--;}}cout<<res<<endl;return 0;}
