#include<iostream>
#include<string>
#include<climits>
using namespace std;
int main(){string s;cin>>s;int i=0,sign=1;long long res=0;while(i<(int)s.size()&&s[i]==" ")i++;if(i<(int)s.size()&&(s[i]=="+"||s[i]=="-")){if(s[i]=="-")sign=-1;i++;}while(i<(int)s.size()&&isdigit(s[i])){res=res*10+(s[i++]-"0");if(res*sign>=INT_MAX)break;if(res*sign<=INT_MIN)break;}res*=sign;res=max((long long)INT_MIN,min((long long)INT_MAX,res));cout<<(int)res<<"\n";}
