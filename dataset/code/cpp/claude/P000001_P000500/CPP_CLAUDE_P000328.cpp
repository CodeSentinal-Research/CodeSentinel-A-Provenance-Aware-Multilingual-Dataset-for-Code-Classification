#include<iostream>
using namespace std;
int main(){string s;cin>>s;int f[256]={};for(char c:s)f[(unsigned char)c]++;for(int i=0;i<(int)s.size();i++)if(f[(unsigned char)s[i]]==1){cout<<i<<"\n";return 0;}cout<<-1<<"\n";}
