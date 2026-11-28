#include<iostream>
#include<string>
using namespace std;
int main(){int n;cin>>n;cin.ignore();string a="",s;for(int i=0;i<n;i++){getline(cin,s);a+=s;}int m;cin>>m;cin.ignore();string b="";for(int i=0;i<m;i++){getline(cin,s);b+=s;}cout<<(a==b?"Yes":"No")<<"\n";}
