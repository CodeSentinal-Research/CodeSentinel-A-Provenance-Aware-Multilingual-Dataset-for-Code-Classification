#include<iostream>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x){cout<<m<<"\n";return 0;}if(m>lo&&a[m-1]==x){cout<<m-1<<"\n";return 0;}if(m<hi&&a[m+1]==x){cout<<m+1<<"\n";return 0;}if(a[m]<x)lo=m+2;else hi=m-2;}cout<<-1<<"\n";}
