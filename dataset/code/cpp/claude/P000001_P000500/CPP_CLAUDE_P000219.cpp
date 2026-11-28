#include<iostream>
using namespace std;
int main(){int n,k;cin>>n>>k;long long a[n];for(auto&x:a)cin>>x;long long p=1;for(int i=n-k;i<n;i++)p*=a[i];cout<<p<<"\n";}
