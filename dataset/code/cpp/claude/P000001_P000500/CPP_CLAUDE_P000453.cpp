#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1,res=-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]==m){res=m;hi=m-1;}else if(a[m]<m)lo=m+1;else hi=m-1;}cout<<res<<"\n";}
