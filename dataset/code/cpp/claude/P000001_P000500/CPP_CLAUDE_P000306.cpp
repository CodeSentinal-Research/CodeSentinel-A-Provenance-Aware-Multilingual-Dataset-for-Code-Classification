#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){string expr;getline(cin,expr);
stack<long long>stk;long long num=0;char op='+';
for(int i=0;i<=(int)expr.size();i++){
    char c=i<(int)expr.size()?expr[i]:'\0';
    if(isdigit(c))num=num*10+(c-'0');
    else if(c!=' '){
        if(op=='+')stk.push(num);
        else if(op=='-')stk.push(-num);
        else if(op=='*'){long long t=stk.top();stk.pop();stk.push(t*num);}
        else{long long t=stk.top();stk.pop();stk.push(t<0?-((-t)/num):(t/num));}
        op=c;num=0;
    }
}
long long res=0;while(!stk.empty()){res+=stk.top();stk.pop();}cout<<res<<"\n";}
