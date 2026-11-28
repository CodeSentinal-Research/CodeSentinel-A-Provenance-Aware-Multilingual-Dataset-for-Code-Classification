#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<pair<int,int>>v(n);for(auto&p:v)cin>>p.first>>p.second;sort(v.begin(),v.end(),[](auto&a,auto&b){return a.second<b.second;});int cnt=1,e=v[0].second;for(int i=1;i<n;i++)if(v[i].first>e){cnt++;e=v[i].second;}cout<<cnt<<"\n";}
