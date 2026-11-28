#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){string s;getline(cin,s);string res="";stack<int>stk;
for(char c:s){
    if(c=='(')stk.push(res.size());
    else if(c==')'){int st=stk.top();stk.pop();reverse(res.begin()+st,res.end());}
    else res+=c;
}cout<<res<<"\n";}
