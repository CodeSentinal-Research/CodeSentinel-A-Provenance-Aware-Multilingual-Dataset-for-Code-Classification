#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int cnt[26]={};bool seen[26]={};for(char c:s)cnt[c-'a']++;string stk="";for(char c:s){cnt[c-'a']--;if(seen[c-'a'])continue;while(!stk.empty()&&stk.back()>c&&cnt[stk.back()-'a']>0){seen[stk.back()-'a']=false;stk.pop_back();}stk+=c;seen[c-'a']=true;}cout<<stk<<"\n";}
