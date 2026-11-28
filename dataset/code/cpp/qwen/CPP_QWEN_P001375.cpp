#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);bool f=false;for(int i=0;i<n;i++){cin>>a[i];if(a[i]==t)f=true;}cout<<(f?"Present":"Missing")<<endl;return 0;}
