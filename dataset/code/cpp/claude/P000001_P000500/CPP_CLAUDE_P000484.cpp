#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){string s;cin>>s;stack<pair<string,int>>stk;string cur="";int num=0;
for(char c:s){
    if(isdigit(c))num=num*10+(c-'0');
    else if(c=='['){stk.push({cur,num});cur="";num=0;}
    else if(c==']'){auto[prev,n]=stk.top();stk.pop();string rep="";for(int i=0;i<n;i++)rep+=cur;cur=prev+rep;}
    else cur+=c;
}
cout<<cur<<"\n";}
