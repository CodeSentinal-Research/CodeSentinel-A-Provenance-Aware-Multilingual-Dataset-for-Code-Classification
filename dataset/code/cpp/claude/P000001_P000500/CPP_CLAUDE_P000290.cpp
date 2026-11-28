#include<iostream>
#include<string>
using namespace std;
int main(){string t,p;cin>>t>>p;int n=t.size(),m=p.size(),need[256]={},win[256]={},matched=0;for(char c:p)need[(unsigned char)c]++;for(int i=0;i<m;i++){win[(unsigned char)t[i]]++;if(win[(unsigned char)t[i]]<=need[(unsigned char)t[i]])matched++;}if(matched==m)cout<<0<<" ";for(int i=m;i<n;i++){int in=(unsigned char)t[i],out=(unsigned char)t[i-m];win[in]++;if(win[in]<=need[in])matched++;win[out]--;if(win[out]<need[out])matched--;if(matched==m)cout<<i-m+1<<" ";}cout<<"\n";}
