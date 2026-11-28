#include<iostream>
#include<cmath>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(lo<hi){if(abs(a[lo]-x)<=abs(a[hi]-x))hi--;else lo++;}cout<<a[lo]<<"\n";}
