#include<iostream>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int k;cin>>k;
unordered_map<int,int>cnt;cnt[0]=1;int odds=0;long long ans=0;
for(int v:a){odds+=v%2;ans+=cnt[odds-k];cnt[odds]++;}cout<<ans<<"\n";}
