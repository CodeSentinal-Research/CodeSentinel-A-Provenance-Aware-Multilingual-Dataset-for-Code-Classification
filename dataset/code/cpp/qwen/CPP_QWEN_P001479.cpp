#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int l=0,r=n-1,mn=1e9,mx=-1e9;for(int i=1;i<n;i++)if(a[i]<a[i-1])mn=min(mn,a[i]);for(int i=n-2;i>=0;i--)if(a[i]>a[i+1])mx=max(mx,a[i]);int res=0;while(res<n&&a[res]<=mn)res++;int res2=n-1;while(res2>=0&&a[res2]>=mx)res2--;cout<<max(0,res2-res+1)<<endl;return 0;}
