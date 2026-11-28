#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);long long tot=0,lft=0;for(auto&v:a){cin>>v;tot+=v;}
for(int i=0;i<n;i++){if(lft==tot-lft-a[i]){cout<<i<<"\n";return 0;}lft+=a[i];}cout<<-1<<"\n";}
