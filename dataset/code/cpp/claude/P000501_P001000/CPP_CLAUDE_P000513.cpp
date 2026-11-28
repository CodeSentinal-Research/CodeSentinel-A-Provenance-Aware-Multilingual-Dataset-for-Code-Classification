#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int opens=0,closes=0;
for(char c:s){if(c=='(')opens++;else{if(opens>0)opens--;else closes++;}}
cout<<opens+closes<<"\n";}
