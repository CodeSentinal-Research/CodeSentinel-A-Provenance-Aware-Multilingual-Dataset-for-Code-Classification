#include<iostream>
#include<unordered_map>
using namespace std;
int main(){string s;cin>>s;unordered_map<char,int>pos;int l=0,best=0;for(int r=0;r<(int)s.size();r++){if(pos.count(s[r])&&pos[s[r]]>=l)l=pos[s[r]]+1;pos[s[r]]=r;best=max(best,r-l+1);}cout<<best<<"\n";}
