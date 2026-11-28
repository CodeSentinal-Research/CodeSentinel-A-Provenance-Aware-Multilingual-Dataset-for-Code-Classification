#include<iostream>
#include<string>
using namespace std;
int main(){string s1,s2;cin>>s1>>s2;int m=s1.size(),n=s2.size();if(m>n){cout<<"No\n";return 0;}int need[26]={},win[26]={},matched=0;for(int i=0;i<m;i++){need[s1[i]-'a']++;win[s2[i]-'a']++;}for(int i=0;i<26;i++)if(win[i]==need[i])matched++;if(matched==26){cout<<"Yes\n";return 0;}for(int i=m;i<n;i++){int in=s2[i]-'a',out=s2[i-m]-'a';if(win[in]==need[in])matched--;win[in]++;if(win[in]==need[in])matched++;if(win[out]==need[out])matched--;win[out]--;if(win[out]==need[out])matched++;if(matched==26){cout<<"Yes\n";return 0;}}cout<<"No\n";}
