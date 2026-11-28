#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){string s;int k;cin>>s>>k;vector<pair<char,int>>stk;for(char c:s){if(!stk.empty()&&stk.back().first==c){stk.back().second++;if(stk.back().second==k)stk.pop_back();}else stk.push_back({c,1});}string res="";for(auto&p:stk)res+=string(p.second,p.first);cout<<res<<"\n";}
