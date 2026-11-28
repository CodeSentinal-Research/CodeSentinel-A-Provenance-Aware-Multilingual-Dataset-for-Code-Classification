#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<int>res(n);int l=0,r=n-1;for(int i=0;i<n;i++){int sq=a[i]*a[i];if(sq>=res[r])res[r--]=sq;else res[l++]=sq;}for(int x:res)cout<<x<<" ";cout<<endl;return 0;}
