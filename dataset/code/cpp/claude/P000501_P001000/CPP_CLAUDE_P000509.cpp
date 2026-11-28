#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){string s;cin>>s;string stk="";
for(char c:s){if(isdigit(c)){if(!stk.empty()&&!isdigit(stk.back()))stk.pop_back();}else stk+=c;}
cout<<stk<<"\n";}
