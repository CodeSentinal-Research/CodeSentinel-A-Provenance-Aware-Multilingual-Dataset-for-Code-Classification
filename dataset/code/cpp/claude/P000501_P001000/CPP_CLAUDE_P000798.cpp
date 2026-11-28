#include<iostream>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;
unordered_map<int,int>pre;pre[0]=-1;int s=0,best=0;
for(int i=0;i<n;i++){s+=(a[i]==1?1:-1);if(pre.count(s))best=max(best,i-pre[s]);else pre[s]=i;}
cout<<best<<"\n";}
