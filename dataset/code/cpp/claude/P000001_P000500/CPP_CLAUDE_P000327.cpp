#include<iostream>
#include<string>
using namespace std;
int main(){string note,mag;cin>>note;getline(cin,mag);int fn[256]={},fm[256]={};for(char c:note)fn[(unsigned char)c]++;for(char c:mag)fm[(unsigned char)c]++;for(int i=0;i<256;i++)if(fn[i]>fm[i]){cout<<"No\n";return 0;}cout<<"Yes\n";}
