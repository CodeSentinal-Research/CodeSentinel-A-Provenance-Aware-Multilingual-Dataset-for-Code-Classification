#include<iostream>
#include<stack>
using namespace std;
int main(){int n;cin>>n;stack<int>stk,mstk;while(n--){string cmd;cin>>cmd;if(cmd=="push"){int x;cin>>x;stk.push(x);mstk.push(mstk.empty()?x:min(x,mstk.top()));}else if(cmd=="pop"){stk.pop();mstk.pop();}else if(cmd=="top")cout<<stk.top()<<"\n";else cout<<mstk.top()<<"\n";}}
