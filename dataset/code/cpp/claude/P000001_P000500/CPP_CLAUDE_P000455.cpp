#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main(){int n,d;cin>>n>>d;vector<int>w(n);for(auto&v:w)cin>>v;long long lo=*max_element(w.begin(),w.end()),hi=accumulate(w.begin(),w.end(),0LL);auto ok=[&](long long cap){int days=1;long long c=0;for(int v:w){if(c+v>cap){days++;c=v;}else c+=v;}return days<=d;};while(lo<hi){long long mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}cout<<lo<<"\n";}
