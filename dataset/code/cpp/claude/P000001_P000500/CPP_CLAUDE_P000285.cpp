#include<iostream>
#include<string>
using namespace std;
int main(){string s1,s2;cin>>s1>>s2;int i=0;for(char c:s2)if(i<(int)s1.size()&&c==s1[i])i++;cout<<(i==(int)s1.size()?"Yes":"No")<<"\n";}
