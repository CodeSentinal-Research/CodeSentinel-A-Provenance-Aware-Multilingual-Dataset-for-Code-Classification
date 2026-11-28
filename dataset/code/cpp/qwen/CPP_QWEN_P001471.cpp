#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int l=0,r=n-1;long long res=0;while(l<r){res=max(res,(long long)min(a[l],a[r])*(r-l));if(a[l]<a[r])l++;else r--;}cout<<res<<endl;return 0;}
