#include<iostream>
#include<string>
using namespace std;
int main(){string s,c;cin>>s>>c;size_t p=s.find(c[0]);cout<<(p==string::npos?-1:(int)p)<<"\n";}
