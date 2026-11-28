#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;for(int i=0;i<n;i++)if(a[i]<0){cout<<i<<"\n";return 0;}cout<<-1<<"\n";}
