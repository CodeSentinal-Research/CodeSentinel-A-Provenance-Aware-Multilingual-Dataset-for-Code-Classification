#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){string s;cin>>s;stack<int>stk;stk.push(0);
for(char c:s){
    if(c=='(')stk.push(0);
    else{int v=stk.top();stk.pop();stk.top()+=v?2*v:1;}
}cout<<stk.top()<<"\n";}
