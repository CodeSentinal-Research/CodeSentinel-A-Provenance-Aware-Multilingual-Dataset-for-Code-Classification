#include<iostream>
#include<set>
using namespace std;
int main(){int n;cin>>n;set<int>s;for(int i=0;i<n;i++){int x;cin>>x;s.insert(x);}int q;cin>>q;while(q--){int x;cin>>x;cout<<(s.count(x)?"Found":"Not Found")<<"\n";}}
