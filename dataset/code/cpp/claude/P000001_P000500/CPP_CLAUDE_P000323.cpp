#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int a=count(s.begin(),s.end(),'A');bool ok=a<=1&&s.find("LLL")==string::npos;cout<<(ok?"Yes":"No")<<"\n";}
