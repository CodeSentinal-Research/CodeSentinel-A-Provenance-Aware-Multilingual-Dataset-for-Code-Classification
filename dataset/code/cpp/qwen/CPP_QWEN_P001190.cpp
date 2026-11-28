#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<long long>s(n,0),h(n,0);s[0]=a[0];for(int i=1;i<n;i++){h[i]=max(h[i-1],s[i-1]);s[i]=max(s[i-1],h[i-1]-a[i]);}cout<<max(h[n-1],s[n-1])<<endl;return 0;}
