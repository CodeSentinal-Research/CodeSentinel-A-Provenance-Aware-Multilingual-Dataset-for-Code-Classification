#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;int val;cin>>val;
a.erase(remove(a.begin(),a.end(),val),a.end());for(int i=0;i<(int)a.size();i++)cout<<a[i]<<" \n"[i+1==(int)a.size()];}
