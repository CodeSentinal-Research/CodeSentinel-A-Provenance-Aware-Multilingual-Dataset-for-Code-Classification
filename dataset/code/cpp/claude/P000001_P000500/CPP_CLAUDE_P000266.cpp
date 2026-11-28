#include<iostream>
#include<string>
using namespace std;
int main(){string s,c;cin>>s>>c;string r="";for(char x:s)if(x!=c[0])r+=x;cout<<r<<"\n";}
