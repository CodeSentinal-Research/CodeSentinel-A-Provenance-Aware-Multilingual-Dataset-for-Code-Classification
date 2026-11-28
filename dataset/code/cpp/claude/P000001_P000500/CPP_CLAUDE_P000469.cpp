#include<iostream>
using namespace std;
int main(){int n,x;cin>>n>>x;int a[n];for(auto&v:a)cin>>v;int first=-1,last=-1;for(int i=0;i<n;i++)if(a[i]==x){if(first==-1)first=i;last=i;}cout<<first<<" "<<last<<"\n";}
