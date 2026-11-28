#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);long long s=0;
for(auto&v:a)cin>>v;for(int i=0;i<n;i++){s+=a[i];cout<<s<<" \n"[i==n-1];}}
