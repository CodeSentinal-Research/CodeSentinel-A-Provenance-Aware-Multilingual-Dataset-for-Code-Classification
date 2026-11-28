#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;string vow="aeiouAEIOU";int i=0,j=s.size()-1;while(i<j){while(i<j&&vow.find(s[i])==string::npos)i++;while(i<j&&vow.find(s[j])==string::npos)j--;if(i<j){swap(s[i],s[j]);i++;j--;}}cout<<s<<"\n";}
