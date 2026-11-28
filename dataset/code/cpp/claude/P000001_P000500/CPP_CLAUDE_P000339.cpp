#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;string v="aeiouAEIOU";int n=s.size(),a=0,b=0;for(int i=0;i<n/2;i++)if(v.find(s[i])!=string::npos)a++;for(int i=n/2;i<n;i++)if(v.find(s[i])!=string::npos)b++;cout<<(a==b?"Yes":"No")<<"\n";}
