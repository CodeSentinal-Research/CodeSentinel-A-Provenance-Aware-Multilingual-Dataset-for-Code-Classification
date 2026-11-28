#include<iostream>
using namespace std;
int main(){string s;cin>>s;for(int i=0;i<(int)s.size();i++){if(i%2==0)cout<<s[i];else cout<<(char)(s[i-1]+s[i]-'0');}cout<<"\n";}
