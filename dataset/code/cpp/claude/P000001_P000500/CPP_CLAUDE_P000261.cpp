#include<iostream>
#include<cctype>
using namespace std;
int main(){string s;cin>>s;for(auto&c:s)c=isupper(c)?tolower(c):islower(c)?toupper(c):c;cout<<s<<"\n";}
