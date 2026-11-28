#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;
string s;int idx;
long long calc(){
    stack<long long>stk;long long num=0;char sign='+';
    while(idx<(int)s.size()){char c=s[idx++];
        if(isdigit(c))num=num*10+(c-'0');
        else if(c=='(')num=calc();
        if((!isdigit(c)&&c!=' ')||idx==(int)s.size()){
            if(sign=='+')stk.push(num);else if(sign=='-')stk.push(-num);
            else if(sign=='*'){long long t=stk.top();stk.pop();stk.push(t*num);}
            else{long long t=stk.top();stk.pop();stk.push((long long)(t/num));}
            if(c==')')break;sign=c;num=0;
        }
    }long long r=0;while(!stk.empty()){r+=stk.top();stk.pop();}return r;
}
int main(){getline(cin,s);idx=0;cout<<calc()<<"\n";}
