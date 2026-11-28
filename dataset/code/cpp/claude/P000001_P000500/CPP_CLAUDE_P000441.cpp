#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(lo<hi){int m=(lo+hi+1)/2;if(a[m]>=a[lo])lo=m;else hi=m-1;}cout<<a[lo]<<"\n";}
