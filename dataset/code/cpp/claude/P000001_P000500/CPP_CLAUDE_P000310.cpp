#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){string a,b;cin>>a>>b;int la=a.size()-1,lb=b.size()-1,carry=0;string res="";
while(la>=0||lb>=0||carry){int s=carry;if(la>=0)s+=a[la--]-'0';if(lb>=0)s+=b[lb--]-'0';res+=(char)('0'+s%2);carry=s/2;}
if(res.empty())res="0";reverse(res.begin(),res.end());cout<<res<<"\n";}
