#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)if(a[i]%2!=0){cout<<i<<endl;return 0;}cout<<-1<<endl;return 0;}
