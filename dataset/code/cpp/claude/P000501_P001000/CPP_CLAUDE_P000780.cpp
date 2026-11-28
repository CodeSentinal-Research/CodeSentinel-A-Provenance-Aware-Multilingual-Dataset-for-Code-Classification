#include<iostream>
using namespace std;
int main(){int n;cin>>n;long long s=0;int v;
for(int i=0;i<n;i++){cin>>v;s+=v;cout<<s<<" \n"[i==n-1];}}
