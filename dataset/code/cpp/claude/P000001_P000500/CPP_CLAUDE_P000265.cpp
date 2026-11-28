#include<iostream>
#include<set>
using namespace std;
int main(){string s;cin>>s;set<char>seen;string r="";for(char c:s)if(!seen.count(c)){r+=c;seen.insert(c);}cout<<r<<"\n";}
