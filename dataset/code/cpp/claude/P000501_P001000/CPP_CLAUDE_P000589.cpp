#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int val;cin>>val;
bool removed=false;vector<int>res;for(int v:a){if(!removed&&v==val){removed=true;continue;}res.push_back(v);}
for(int i=0;i<(int)res.size();i++)cout<<res[i]<<" \n"[i+1==(int)res.size()];}
