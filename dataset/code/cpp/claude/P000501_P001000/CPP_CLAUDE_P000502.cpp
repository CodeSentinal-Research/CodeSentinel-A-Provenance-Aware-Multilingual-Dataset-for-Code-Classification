#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
int main(){string line;getline(cin,line);istringstream iss(line);stack<long long>stk;string t;
while(iss>>t){
    if(t=="+"||t=="-"||t=="*"||t=="/"){long long b=stk.top();stk.pop();long long a=stk.top();stk.pop();
    if(t=="+")stk.push(a+b);else if(t=="-")stk.push(a-b);else if(t=="*")stk.push(a*b);else stk.push((long long)(a/b));}
    else stk.push(stoll(t));
}cout<<stk.top()<<"\n";}
