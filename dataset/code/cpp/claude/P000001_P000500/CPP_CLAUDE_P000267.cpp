#include<iostream>
#include<string>
using namespace std;
int main(){string s,o,n;cin>>s>>o>>n;for(char&c:s)if(c==o[0])c=n[0];cout<<s<<"\n";}
