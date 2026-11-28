#include<bits/stdc++.h>
using namespace std;
int main(){int n,s;cin>>n>>s;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<bool>f(s+1,false);f[0]=true;for(int x:a)for(int j=s;j>=x;j--)if(f[j-x])f[j]=true;cout<<(f[s]?"YES":"NO")<<endl;return 0;}
