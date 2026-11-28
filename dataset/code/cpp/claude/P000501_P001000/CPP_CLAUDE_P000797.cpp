#include<iostream>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;
unordered_map<int,int>cnt;cnt[0]=1;int s=0;long long ans=0;
for(int v:a){s+=(v==1?1:-1);ans+=cnt[s];cnt[s]++;}cout<<ans<<"\n";}
