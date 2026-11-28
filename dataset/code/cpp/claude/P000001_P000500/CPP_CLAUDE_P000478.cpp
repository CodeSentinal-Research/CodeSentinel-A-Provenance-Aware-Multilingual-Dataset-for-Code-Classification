#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n,c;cin>>n>>c;vector<int>stalls(n);for(auto&v:stalls)cin>>v;sort(stalls.begin(),stalls.end());auto ok=[&](int d){int cnt=1,last=stalls[0];for(int i=1;i<n;i++)if(stalls[i]-last>=d){cnt++;last=stalls[i];}return cnt>=c;};int lo=1,hi=stalls[n-1]-stalls[0],ans=0;while(lo<=hi){int mid=(lo+hi)/2;if(ok(mid)){ans=mid;lo=mid+1;}else hi=mid-1;}cout<<ans<<"\n";}
