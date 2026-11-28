#include<iostream>
using namespace std;
int main(){string s,t;cin>>s>>t;int diff=0;for(char c:s)diff^=c;for(char c:t)diff^=c;cout<<(char)diff<<"\n";}
