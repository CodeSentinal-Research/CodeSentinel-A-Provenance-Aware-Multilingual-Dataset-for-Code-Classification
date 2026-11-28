#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int n=s.size(),i=0;string r="";while(i<n){int cnt=1;while(i+cnt<n&&s[i+cnt]==s[i])cnt++;r+=s[i];if(cnt>1)r+=to_string(cnt);i+=cnt;}cout<<r<<"\n";}
