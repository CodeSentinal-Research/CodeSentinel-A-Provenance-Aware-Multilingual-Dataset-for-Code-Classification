#include<iostream>
using namespace std;
int main(){string s;cin>>s;int f[256]={};for(char c:s)f[(unsigned char)c]++;char res=0;for(char c:s)if(f[(unsigned char)c]==1)res=c;cout<<(res?string(1,res):"-1")<<"\n";}
