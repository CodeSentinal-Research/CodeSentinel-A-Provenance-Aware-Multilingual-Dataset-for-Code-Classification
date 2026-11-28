#include<iostream>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(lo<=hi){int m=(lo+hi)/2;if(a[m]==x){cout<<m<<"\n";return 0;}if(a[lo]<=a[m]){if(a[lo]<=x&&x<a[m])hi=m-1;else lo=m+1;}else{if(a[m]<x&&x<=a[hi])lo=m+1;else hi=m-1;}}cout<<-1<<"\n";}
