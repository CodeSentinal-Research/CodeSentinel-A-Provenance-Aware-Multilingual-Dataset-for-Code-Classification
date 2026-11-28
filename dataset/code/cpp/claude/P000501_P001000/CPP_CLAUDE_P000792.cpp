#include<iostream>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int goal;cin>>goal;
unordered_map<int,int>cnt;cnt[0]=1;int s=0;long long ans=0;
for(int v:a){s+=v;ans+=cnt[s-goal];cnt[s]++;}cout<<ans<<"\n";}
