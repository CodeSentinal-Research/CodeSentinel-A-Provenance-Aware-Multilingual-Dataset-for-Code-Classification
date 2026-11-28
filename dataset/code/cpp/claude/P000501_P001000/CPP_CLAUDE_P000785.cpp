#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<long long>a(n);long long tot=0,left=0;for(auto&v:a){cin>>v;tot+=v;}
for(int i=0;i<n;i++){if(left==tot-left-a[i]){cout<<i<<"\n";return 0;}left+=a[i];}cout<<-1<<"\n";}
