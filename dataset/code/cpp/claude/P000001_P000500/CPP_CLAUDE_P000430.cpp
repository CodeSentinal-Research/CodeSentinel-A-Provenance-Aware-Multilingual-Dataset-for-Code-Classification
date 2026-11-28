#include<iostream>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;for(int i=n-1;i>=0;i--)if(a[i]==x){cout<<i<<"\n";return 0;}cout<<-1<<"\n";}
