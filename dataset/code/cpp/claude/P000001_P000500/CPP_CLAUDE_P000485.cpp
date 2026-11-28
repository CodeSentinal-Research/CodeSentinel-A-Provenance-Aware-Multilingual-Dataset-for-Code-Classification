#include<iostream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(auto&v:a)cin>>v;vector<int>stk;for(int x:a){bool alive=true;while(alive&&x<0&&!stk.empty()&&stk.back()>0){if(stk.back()<-x)stk.pop_back();else if(stk.back()==-x){stk.pop_back();alive=false;}else alive=false;}if(alive)stk.push_back(x);}for(int i=0;i<(int)stk.size();i++)cout<<stk[i]<<" \n"[i+1==(int)stk.size()];}
