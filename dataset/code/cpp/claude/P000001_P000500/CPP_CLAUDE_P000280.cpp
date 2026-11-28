#include<iostream>
#include<unordered_map>
using namespace std;
int main(){string s1,s2;cin>>s1>>s2;unordered_map<char,int>f;for(char c:s1)f[c]++;for(char c:s2)f[c]--;int d=0;for(auto&p:f)if(p.second<0)d+=-p.second;cout<<(d<=1?"Yes":"No")<<"\n";}
