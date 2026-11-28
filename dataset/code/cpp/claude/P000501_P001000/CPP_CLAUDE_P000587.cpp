#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int k;cin>>k;vector<int>all;
for(int i=0;i<k;i++){int sz;cin>>sz;for(int j=0;j<sz;j++){int v;cin>>v;all.push_back(v);}}
sort(all.begin(),all.end());for(int i=0;i<(int)all.size();i++)cout<<all[i]<<" \n"[i+1==(int)all.size()];}
