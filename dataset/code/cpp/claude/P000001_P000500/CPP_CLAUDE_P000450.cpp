#include<iostream>
using namespace std;
int main(){int n,k;cin>>n>>k;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n;while(lo<hi){int m=(lo+hi)/2;if(a[m]-(m+1)>=k)hi=m;else lo=m+1;}cout<<lo+k<<"\n";}
