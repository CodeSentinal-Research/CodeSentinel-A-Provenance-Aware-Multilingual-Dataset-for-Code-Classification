#include<bits/stdc++.h>
using namespace std;
int main(){int n,l;cin>>n>>l;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];sort(a.begin(),a.end());int res=0,i=0,j=n-1;while(i<=j){if(a[i]+a[j]<=l){i++;j--;}else j--;res++;}cout<<res<<endl;return 0;}
