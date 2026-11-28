#include<iostream>
#include<string>
using namespace std;
int main(){int n;cin>>n;string s="1";for(int i=1;i<n;i++){string t="";int j=0;while(j<(int)s.size()){int cnt=1;while(j+cnt<(int)s.size()&&s[j+cnt]==s[j])cnt++;t+=to_string(cnt)+s[j];j+=cnt;}s=t;}cout<<s<<"\n";}
