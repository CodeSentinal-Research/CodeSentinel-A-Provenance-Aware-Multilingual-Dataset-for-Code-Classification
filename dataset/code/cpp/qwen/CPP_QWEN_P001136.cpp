#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<long long>t(max(3,n+1));t[0]=0;t[1]=1;t[2]=1;for(int i=3;i<=n;i++)t[i]=t[i-1]+t[i-2]+t[i-3];cout<<t[n]<<endl;return 0;}
