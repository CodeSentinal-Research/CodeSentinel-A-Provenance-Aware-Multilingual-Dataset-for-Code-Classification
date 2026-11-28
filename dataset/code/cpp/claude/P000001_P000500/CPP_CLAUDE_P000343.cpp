#include<iostream>
#include<cmath>
using namespace std;
int main(){string w1,w2;cin>>w1>>w2;int f[26]={};for(char c:w1)f[c-'a']++;for(char c:w2)f[c-'a']--;for(int i=0;i<26;i++)if(abs(f[i])>3){cout<<"No\n";return 0;}cout<<"Yes\n";}
