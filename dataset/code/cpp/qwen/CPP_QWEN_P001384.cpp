#include<bits/stdc++.h>
using namespace std;
int main(){int n,q;cin>>n>>q;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];while(q--){int t;cin>>t;bool f=false;for(int i=0;i<n;i++)if(a[i]==t){f=true;break;}cout<<(f?"Found":"Not Found")<<"\n";}return 0;}
