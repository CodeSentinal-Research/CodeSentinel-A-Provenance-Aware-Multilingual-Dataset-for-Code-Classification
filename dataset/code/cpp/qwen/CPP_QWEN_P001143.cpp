#include<bits/stdc++.h>
using namespace std;
int main(){int n,t;cin>>n>>t;vector<int>a(n);int sum=0;for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}if((sum-t)%2!=0||abs(t)>sum){cout<<0<<endl;return 0;}int target=(sum-t)/2;vector<long long>f(target+1,0);f[0]=1;for(int x:a)for(int j=target;j>=x;j--)f[j]+=f[j-x];cout<<f[target]<<endl;return 0;}
