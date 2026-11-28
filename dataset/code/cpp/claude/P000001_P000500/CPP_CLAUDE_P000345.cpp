#include<iostream>
#include<set>
using namespace std;
int main(){string s1,s2;cin>>s1>>s2;set<char>a(s1.begin(),s1.end()),b(s2.begin(),s2.end());cout<<(a==b?"Yes":"No")<<"\n";}
