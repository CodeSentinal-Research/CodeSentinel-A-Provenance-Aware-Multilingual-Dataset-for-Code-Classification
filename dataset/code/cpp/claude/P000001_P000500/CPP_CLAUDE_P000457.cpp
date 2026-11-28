#include<iostream>
#include<vector>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);for(auto&v:a)cin>>v;int lo=1,hi=*max_element(a.begin(),a.end());auto ok=[&](int d){long long s=0;for(int v:a)s+=(v+d-1)/d;return s<=t;};while(lo<hi){int mid=(lo+hi)/2;if(ok(mid))hi=mid;else lo=mid+1;}cout<<lo<<"\n";}
