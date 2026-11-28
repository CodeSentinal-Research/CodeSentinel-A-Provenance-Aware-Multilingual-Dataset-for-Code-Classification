#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;bool ok=false;int i=0,n=s.size();
if(i<n&&(s[i]=='+'||s[i]=='-'))i++;
int digits=0;while(i<n&&isdigit(s[i])){i++;digits++;}
bool hasDot=false;if(i<n&&s[i]=='.'){hasDot=true;i++;while(i<n&&isdigit(s[i])){i++;digits++;}}
if(digits==0){cout<<"No\n";return 0;}
if(i<n&&(s[i]=='e'||s[i]=='E')){i++;if(i<n&&(s[i]=='+'||s[i]=='-'))i++;int ed=0;while(i<n&&isdigit(s[i])){i++;ed++;}if(!ed){cout<<"No\n";return 0;}}
cout<<(i==n?"Yes":"No")<<"\n";}
