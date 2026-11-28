#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;string t=s+s;cout<<(t.substr(1,t.size()-2).find(s)!=string::npos?"Yes":"No")<<"\n";}
