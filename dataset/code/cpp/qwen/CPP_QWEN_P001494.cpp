#include<bits/stdc++.h>
using namespace std;
int main(){string s;cin>>s;int l=0,r=s.size();vector<int>res;for(char c:s){if(c=='I')res.push_back(l++);else res.push_back(r--);}res.push_back(l);for(int x:res)cout<<x<<" ";cout<<endl;return 0;}
