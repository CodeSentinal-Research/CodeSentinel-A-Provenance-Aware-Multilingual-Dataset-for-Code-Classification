#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];vector<int>pos,neg;for(int x:a){if(x>0)pos.push_back(x);else neg.push_back(x);}vector<int>res;for(int i=0;i<pos.size();i++){res.push_back(pos[i]);res.push_back(neg[i]);}for(int x:res)cout<<x<<" ";cout<<endl;return 0;}
