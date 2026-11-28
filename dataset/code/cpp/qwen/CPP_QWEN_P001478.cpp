#include<bits/stdc++.h>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<pair<int,int>>a(n),b(m);for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;for(int i=0;i<m;i++)cin>>b[i].first>>b[i].second;int i=0,j=0;while(i<n&&j<m){if(a[i].second<b[j].first)i++;else if(b[j].second<a[i].first)j++;else{cout<<max(a[i].first,b[j].first)<<" "<<min(a[i].second,b[j].second)<<"\n";if(a[i].second<b[j].second)i++;else j++;}}return 0;}
