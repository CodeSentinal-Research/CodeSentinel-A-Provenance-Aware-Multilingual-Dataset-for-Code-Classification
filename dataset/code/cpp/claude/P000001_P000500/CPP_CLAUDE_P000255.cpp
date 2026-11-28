#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;string v="aeiouAEIOU",r="";for(char c:s)if(v.find(c)==string::npos)r+=c;cout<<r<<"\n";}
