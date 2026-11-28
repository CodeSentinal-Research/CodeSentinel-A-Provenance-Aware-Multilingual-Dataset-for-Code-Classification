#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<string>w(n);for(auto&s:w)cin>>s;string p=w[0];for(int i=1;i<n;i++){while(w[i].find(p)!=0)p.pop_back();}cout<<p<<"\n";}
