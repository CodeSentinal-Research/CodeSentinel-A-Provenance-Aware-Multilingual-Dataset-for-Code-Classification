#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);for(auto&v:a)cin>>v;long long k;cin>>k;
unordered_map<long long,int>cnt;cnt[0]=1;long long s=0,ans=0;
for(auto v:a){s+=v;ans+=cnt[s-k];cnt[s]++;}cout<<ans<<"\n";}
