#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n],x;for(auto&v:a)cin>>v;cin>>x;for(int i=0;i<n;i++)if(a[i]<x){cout<<i<<"\n";return 0;}cout<<-1<<"\n";}
