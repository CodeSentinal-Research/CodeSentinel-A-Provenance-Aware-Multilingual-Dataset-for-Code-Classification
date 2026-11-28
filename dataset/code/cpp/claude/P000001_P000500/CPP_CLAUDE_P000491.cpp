#include<iostream>
#include<vector>
using namespace std;
int main(){int m;cin>>m;vector<int>target(m);for(auto&v:target)cin>>v;int n;cin>>n;int cur=1;for(int t:target){while(cur<t){cout<<"Push\nPop\n";cur++;}cout<<"Push\n";cur++;}}
