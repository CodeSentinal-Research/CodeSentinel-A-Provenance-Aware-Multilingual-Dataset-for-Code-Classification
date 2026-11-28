#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int n,m;
bool ok(vector<int>&a,long long mid){int s=1;long long c=0;for(int v:a){if(v>mid)return false;if(c+v>mid){s++;c=v;}else c+=v;}return s<=m;}
int main(){cin>>n>>m;vector<int>a(n);for(auto&v:a)cin>>v;long long lo=*max_element(a.begin(),a.end()),hi=accumulate(a.begin(),a.end(),0LL),ans=hi;while(lo<=hi){long long mid=(lo+hi)/2;if(ok(a,mid)){ans=mid;hi=mid-1;}else lo=mid+1;}cout<<ans<<"\n";}
