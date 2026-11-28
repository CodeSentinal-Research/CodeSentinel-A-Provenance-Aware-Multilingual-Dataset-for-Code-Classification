#include<iostream>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1,res=-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]<=x){res=a[m];lo=m+1;}else hi=m-1;}cout<<res<<"\n";}
