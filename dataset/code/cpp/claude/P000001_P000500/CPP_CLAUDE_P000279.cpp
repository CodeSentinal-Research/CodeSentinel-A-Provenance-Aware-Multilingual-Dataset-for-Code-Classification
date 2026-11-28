#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;map<string,vector<string>>g;for(int i=0;i<n;i++){string w;cin>>w;string k=w;sort(k.begin(),k.end());g[k].push_back(w);}for(auto&p:g){for(int i=0;i<(int)p.second.size();i++)cout<<p.second[i]<<" \n"[i+1==(int)p.second.size()];}}
