#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<string>a(n);for(int i=0;i<n;i++)cin>>a[i];for(int i=0;i<n;i++)if(a[i].empty()){cout<<i<<endl;return 0;}cout<<-1<<endl;return 0;}
