#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);int sum=0;for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}if(sum%2!=0){cout<<"NO"<<endl;return 0;}int t=sum/2;vector<bool>f(t+1,false);f[0]=true;for(int x:a)for(int j=t;j>=x;j--)if(f[j-x])f[j]=true;cout<<(f[t]?"YES":"NO")<<endl;return 0;}
