#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int cnt=0,opens=0;
for(char c:s){if(c=='[')opens++;else{if(opens>0)opens--;else cnt++;}}
cout<<(cnt+1)/2<<"\n";}
