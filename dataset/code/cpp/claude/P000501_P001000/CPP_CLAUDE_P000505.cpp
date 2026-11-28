#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;
int main(){string s;getline(cin,s);stack<long long>stk;long long num=0;char sign='+';
for(int i=0;i<(int)s.size();i++){
    if(isdigit(s[i]))num=num*10+(s[i]-'0');
    if((!isdigit(s[i])&&s[i]!=' ')||i==(int)s.size()-1){
        if(sign=='+')stk.push(num);else if(sign=='-')stk.push(-num);
        else if(sign=='*'){long long t=stk.top();stk.pop();stk.push(t*num);}
        else{long long t=stk.top();stk.pop();stk.push((long long)(t/num));}
        sign=s[i];num=0;
    }
}long long res=0;while(!stk.empty()){res+=stk.top();stk.pop();}cout<<res<<"\n";}
