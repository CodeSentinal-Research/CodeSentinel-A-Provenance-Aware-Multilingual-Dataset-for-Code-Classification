#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;int lo=0,hi=n-1;while(hi-lo>2){int m1=lo+(hi-lo)/3,m2=hi-(hi-lo)/3;if(a[m1]<a[m2])lo=m1+1;else hi=m2-1;}int mx=a[lo];for(int i=lo+1;i<=hi;i++)if(a[i]>mx)mx=a[i];cout<<mx<<"\n";}
