#include<iostream>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int p;cin>>p;
long long tot=0;for(int v:a)tot+=v;int r=tot%p;if(r==0){cout<<0<<"\n";return 0;}
unordered_map<int,int>pre;pre[0]=-1;int s=0,best=n;
for(int i=0;i<n;i++){s=(s+a[i])%p;int t=((s-r)%p+p)%p;if(pre.count(t)&&i-pre[t]<n&&i-pre[t]<best)best=i-pre[t];if(!pre.count(s))pre[s]=i;}
cout<<(best==n?-1:best)<<"\n";}
