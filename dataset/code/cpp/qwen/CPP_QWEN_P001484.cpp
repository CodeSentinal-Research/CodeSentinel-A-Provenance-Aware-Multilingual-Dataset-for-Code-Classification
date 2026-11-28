#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];int res=0;for(int i=0;i<n-1;){int j=i;while(j<n-1&&a[j]<a[j+1])j++;int k=j;while(k<n-1&&a[k]>a[k+1])k++;if(j>i&&k>j)res=max(res,k-i+1);i=k+1;}cout<<res<<endl;return 0;}
