#include<iostream>
#include<string>
using namespace std;
int main(){string s;cin>>s;int n=s.size(),best=0,ones=count(s.begin(),s.end(),'1'),zeros=0;for(int i=0;i<n-1;i++){if(s[i]=='0')zeros++;else ones--;best=max(best,zeros+ones);}cout<<best<<"\n";}
