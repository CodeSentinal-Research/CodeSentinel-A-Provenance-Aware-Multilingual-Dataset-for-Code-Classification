#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool palin(string&s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}
bool check(string&a,string&b){int i=0,j=a.size()-1;while(i<j&&a[i]==b[j]){i++;j--;}return palin(a,i,j)||palin(b,i,j);}
int main(){string a,b;cin>>a>>b;cout<<(check(a,b)||check(b,a)?"Yes":"No")<<"\n";}
