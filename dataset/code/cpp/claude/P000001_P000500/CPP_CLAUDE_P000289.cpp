#include<iostream>
#include<string>
using namespace std;
int main(){string s;int k;cin>>s>>k;int win[26]={},l=0,best=0,mxf=0;for(int r=0;r<(int)s.size();r++){win[s[r]-'A']++;mxf=max(mxf,win[s[r]-'A']);if(r-l+1-mxf>k)win[s[l++]-'A']--;best=max(best,r-l+1);}cout<<best<<"\n";}
