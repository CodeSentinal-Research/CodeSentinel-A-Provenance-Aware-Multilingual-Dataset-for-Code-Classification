#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;
int lo=0,hi=n-1;while(lo<=hi){cout<<a[lo++]<<" ";if(lo<=hi)cout<<a[hi--]<<" ";}cout<<"\n";}
