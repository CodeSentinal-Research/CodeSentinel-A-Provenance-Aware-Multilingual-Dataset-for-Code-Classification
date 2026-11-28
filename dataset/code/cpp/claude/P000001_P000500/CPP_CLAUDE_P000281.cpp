#include<iostream>
using namespace std;
int main(){string s,t;cin>>s>>t;int need[256]={},win[256]={},miss=t.size(),l=0,bs=-1,bl=0;for(char c:t)need[(unsigned char)c]++;for(int r=0;r<(int)s.size();r++){int c=(unsigned char)s[r];win[c]++;if(need[c]>0&&win[c]<=need[c])miss--;while(miss==0){if(bs<0||r-l+1<bs){bs=r-l+1;bl=l;}int lc=(unsigned char)s[l];win[lc]--;if(need[lc]>0&&win[lc]<need[lc])miss++;l++;}}cout<<(bs<0?"":s.substr(bl,bs))<<"\n";}
