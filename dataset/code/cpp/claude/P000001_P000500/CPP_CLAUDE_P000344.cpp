#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<string>words(n);for(auto&w:words)cin>>w;string s;cin>>s;int cnt=0;for(auto&w:words)if(s.substr(0,w.size())==w)cnt++;cout<<cnt<<"\n";}
