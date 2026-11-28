#include<iostream>
#include<string>
using namespace std;
int main(){int n;cin>>n;cin.ignore();int mi=0,ml=INT_MAX;vector<string>v(n);for(int i=0;i<n;i++){getline(cin,v[i]);if((int)v[i].size()<ml){ml=v[i].size();mi=i;}}cout<<mi<<"\n";}
