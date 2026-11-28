#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<string>q(n);for(int i=0;i<n;i++)cin>>q[i];string p;cin>>p;auto chk=[&](string s){int j=0;for(char c:s){if(j<p.size()&&((isupper(c)&&c==p[j])||(!isupper(c)&&j==0))){if(isupper(c))j++;}}return j==p.size();};for(string s:q)cout<<(chk(s)?"true":"false")<<" ";cout<<endl;return 0;}
