#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi)/2;if(m%2)m--;if(a[m]==a[m+1])lo=m+2;else hi=m;}cout<<a[lo]<<"\n";}
