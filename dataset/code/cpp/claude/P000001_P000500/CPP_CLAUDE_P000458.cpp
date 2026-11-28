#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<int>a(n);for(auto&v:a)cin>>v;long long lo=*max_element(a.begin(),a.end()),hi=accumulate(a.begin(),a.end(),0LL);auto ok=[&](long long cap){int p=1;long long c=0;for(int v:a){if(c+v>cap){p++;c=v;}else c+=v;}return p<=m;};while(lo<hi){long long mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}cout<<lo<<"\n";}
