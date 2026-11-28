#include<iostream>
#include<vector>
using namespace std;
int main(){int sz;cin>>sz;vector<int>a(sz);for(auto&v:a)cin>>v;int n;cin>>n;
a.erase(a.begin()+sz-n);for(int i=0;i<(int)a.size();i++)cout<<a[i]<<" \n"[i+1==(int)a.size()];}
