#include<iostream>
#include<vector>
using namespace std;
int main(){int n,h;cin>>n>>h;vector<int>p(n);for(auto&v:p)cin>>v;int lo=1,hi=*max_element(p.begin(),p.end());auto ok=[&](int k){long long s=0;for(int x:p)s+=(x+k-1)/k;return s<=h;};while(lo<hi){int mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}cout<<lo<<"\n";}
