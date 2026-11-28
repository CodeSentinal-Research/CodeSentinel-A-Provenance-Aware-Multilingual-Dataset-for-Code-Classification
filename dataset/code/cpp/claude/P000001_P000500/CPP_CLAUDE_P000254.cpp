#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;string v="aeiouAEIOU";int cnt=0;for(char c:s)if(isalpha(c)&&v.find(c)==string::npos)cnt++;cout<<cnt<<"\n";}
