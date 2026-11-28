#include<iostream>
#include<string>
using namespace std;
bool pal(string&s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}
int main(){string s;cin>>s;int l=0,r=s.size()-1;while(l<r&&s[l]==s[r]){l++;r--;}cout<<(l>=r||pal(s,l+1,r)||pal(s,l,r-1)?"Yes":"No")<<"\n";}
