#include<iostream>
using namespace std;
long long val(string&s){long long v=0;for(char c:s)v=v*10+(c-'a');return v;}
int main(){string a,b,t;cin>>a>>b>>t;cout<<(val(a)+val(b)==val(t)?"Yes":"No")<<"\n";}
