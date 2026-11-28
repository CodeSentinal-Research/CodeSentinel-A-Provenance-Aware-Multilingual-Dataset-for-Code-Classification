#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;int lo=1,hi=n-2;while(lo<hi){int m=(lo+hi)/2;if(a[m]<a[m+1])lo=m+1;else hi=m;}cout<<lo<<"\n";}
