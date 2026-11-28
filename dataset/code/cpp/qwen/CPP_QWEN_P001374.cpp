#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);int cnt=0;for(int i=0;i<n;i++){cin>>a[i];if(a[i]==t)cnt++;}cout<<cnt<<endl;return 0;}
