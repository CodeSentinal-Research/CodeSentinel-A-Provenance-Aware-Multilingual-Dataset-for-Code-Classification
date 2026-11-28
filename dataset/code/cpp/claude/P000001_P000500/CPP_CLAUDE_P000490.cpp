#include<iostream>
#include<string>
using namespace std;
string proc(string s){string r="";for(char c:s){if(c=='#'){if(!r.empty())r.pop_back();}else r+=c;}return r;}
int main(){string s,t;cin>>s>>t;cout<<(proc(s)==proc(t)?"true":"false")<<"\n";}
