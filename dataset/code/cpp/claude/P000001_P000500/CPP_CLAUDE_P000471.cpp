#include<iostream>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;for(int i=0;i<n;i++){int c=0;for(int j=i+1;j<n;j++)if(a[j]<a[i])c++;cout<<c<<" \n"[i==n-1];}}
