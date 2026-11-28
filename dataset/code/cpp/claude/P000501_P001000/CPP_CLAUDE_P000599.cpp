#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);map<int,int>cnt;for(auto&v:a){cin>>v;cnt[v]++;}
vector<int>res;for(int v:a)if(cnt[v]==1)res.push_back(v);
for(int i=0;i<(int)res.size();i++)cout<<res[i]<<" \n"[i+1==(int)res.size()];}
