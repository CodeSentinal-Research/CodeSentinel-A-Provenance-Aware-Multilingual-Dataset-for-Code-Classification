#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){string expr;getline(cin,expr);
stack<int>stk;int num=0,sign=1,res=0;
for(char c:expr){
    if(isdigit(c))num=num*10+(c-'0');
    else if(c=='+'||c=='-'){res+=sign*num;num=0;sign=(c=='+'?1:-1);}
    else if(c=='('){stk.push(res);stk.push(sign);res=0;sign=1;}
    else if(c==')'){res+=sign*num;num=0;sign=stk.top();stk.pop();res=res*sign+stk.top();stk.pop();sign=1;}
}
res+=sign*num;cout<<res<<"\n";}
