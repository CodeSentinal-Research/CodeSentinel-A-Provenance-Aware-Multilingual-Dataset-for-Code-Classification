#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<pair<int,int>>p(n);for(int i=0;i<n;i++){cin>>p[i].first;p[i].second=i;}sort(p.begin(),p.end());vector<bool>vis(n,false);int sw=0;for(int i=0;i<n;i++){if(vis[i]||p[i].second==i)continue;int j=i,c=0;while(!vis[j]){vis[j]=true;j=p[j].second;c++;}sw+=c-1;}cout<<sw<<"\n";}
