#include<iostream>
#include<cmath>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi)/2;if(a[m]<x)lo=m+1;else hi=m;}if(lo>0&&abs(a[lo-1]-x)<abs(a[lo]-x))lo--;cout<<a[lo]<<"\n";}
