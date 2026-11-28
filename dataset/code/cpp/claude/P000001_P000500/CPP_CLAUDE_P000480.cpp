#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;string stk;for(char c:s){if(!stk.empty()&&stk.back()==c)stk.pop_back();else stk+=c;}cout<<stk<<"\n";}
