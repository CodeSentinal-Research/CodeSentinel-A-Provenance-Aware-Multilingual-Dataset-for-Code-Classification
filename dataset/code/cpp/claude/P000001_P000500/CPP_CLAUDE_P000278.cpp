#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int n=s.size();string best="";auto exp=[&](int l,int r){while(l>=0&&r<n&&s[l]==s[r]){l--;r++;}return s.substr(l+1,r-l-1);};for(int i=0;i<n;i++){for(auto&p:{exp(i,i),exp(i,i+1)})if(p.size()>best.size())best=p;}cout<<best<<"\n";}
