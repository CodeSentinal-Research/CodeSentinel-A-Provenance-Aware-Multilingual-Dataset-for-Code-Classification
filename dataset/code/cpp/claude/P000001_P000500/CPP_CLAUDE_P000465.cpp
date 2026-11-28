#include<iostream>
#include<set>
using namespace std;
int main(){int n,d;cin>>n>>d;set<int>s;vector<int>a(n);for(auto&v:a){cin>>v;s.insert(v);}for(int v:a)if(d!=0&&s.count(v+d)){cout<<"Yes\n";return 0;}else if(d==0&&count(a.begin(),a.end(),v)>1){cout<<"Yes\n";return 0;}cout<<"No\n";}
