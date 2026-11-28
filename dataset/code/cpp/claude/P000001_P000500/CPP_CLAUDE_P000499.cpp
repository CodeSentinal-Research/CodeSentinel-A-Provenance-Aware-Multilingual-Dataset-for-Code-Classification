#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){string s;cin>>s;string stk="";for(char c:s){if(!stk.empty()&&stk.back()!=c&&tolower(stk.back())==tolower(c))stk.pop_back();else stk+=c;}cout<<stk<<"\n";}
