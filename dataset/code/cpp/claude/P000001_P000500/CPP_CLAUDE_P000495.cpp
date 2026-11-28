#include<iostream>
#include<stack>
using namespace std;
int main(){int n;cin>>n;stack<pair<int,int>>stk;while(n--){int p;cin>>p;int span=1;while(!stk.empty()&&stk.top().first<=p){span+=stk.top().second;stk.pop();}stk.push({p,span});cout<<span<<"\n";}}
