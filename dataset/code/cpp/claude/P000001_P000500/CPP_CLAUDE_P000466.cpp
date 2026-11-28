#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);for(auto&v:a)cin>>v;sort(a.begin(),a.end());for(int i=0;i<n-2;i++){int lo=i+1,hi=n-1;while(lo<hi){int s=a[i]+a[lo]+a[hi];if(s==t){cout<<"Yes\n";return 0;}else if(s<t)lo++;else hi--;}}cout<<"No\n";}
