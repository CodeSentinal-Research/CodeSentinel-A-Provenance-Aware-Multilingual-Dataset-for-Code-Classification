#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n),b;for(auto&v:a)cin>>v;int m;cin>>m;b.resize(m);for(auto&v:b)cin>>v;
vector<int>res;merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(res));for(int i=0;i<(int)res.size();i++)cout<<res[i]<<" \n"[i+1==(int)res.size()];}
