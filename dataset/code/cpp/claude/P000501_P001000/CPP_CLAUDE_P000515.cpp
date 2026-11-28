#include<iostream>
#include<string>
using namespace std;
int main(){string s;getline(cin,s);int d=0,mx=0;
for(char c:s){if(c=='('){d++;mx=max(mx,d);}else if(c==')')d--;}
cout<<mx<<"\n";}
