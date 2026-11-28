#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>stk;string op;while(n--){cin>>op;if(op=="+")stk.push_back(stk[stk.size()-1]+stk[stk.size()-2]);else if(op=="D")stk.push_back(stk.back()*2);else if(op=="C")stk.pop_back();else stk.push_back(stoi(op));}long long s=0;for(int v:stk)s+=v;cout<<s<<"\n";}
