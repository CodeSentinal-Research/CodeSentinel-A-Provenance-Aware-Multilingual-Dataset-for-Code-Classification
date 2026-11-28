#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];long long p=0,c=0;for(int x:a){long long t=c;c=max(p+x,c);p=t;}cout<<c<<endl;return 0;}
