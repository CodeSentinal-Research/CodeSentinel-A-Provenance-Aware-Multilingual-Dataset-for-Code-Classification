#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;char c;cin>>c;int n=s.size();vector<int>res(n,1e9);int last=-1e9;for(int i=0;i<n;i++){if(s[i]==c)last=i;res[i]=min(res[i],i-last);}last=1e9;for(int i=n-1;i>=0;i--){if(s[i]==c)last=i;res[i]=min(res[i],last-i);}for(int x:res)cout<<x<<" ";cout<<endl;return 0;}
