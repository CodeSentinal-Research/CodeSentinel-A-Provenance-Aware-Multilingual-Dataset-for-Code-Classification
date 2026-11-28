#include<bits/stdc++.h>
using namespace std;
int main(){string s;char c;cin>>s>>c;int idx=s.find(c);reverse(s.begin(),s.begin()+idx+1);cout<<s<<endl;return 0;}
