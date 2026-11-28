#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;
int main(){int n,m;cin>>n>>m;vector<int>res(n,0);stack<int>stk;int prev=0;
for(int k=0;k<m;k++){string log;cin>>log;int fid,time;string typ;istringstream ss(log);string t;getline(ss,t,':');fid=stoi(t);getline(ss,typ,':');getline(ss,t);time=stoi(t);
if(typ=="start"){if(!stk.empty())res[stk.top()]+=time-prev;stk.push(fid);prev=time;}
else{res[stk.top()]+=time-prev+1;stk.pop();prev=time+1;}}
for(int i=0;i<n;i++)cout<<res[i]<<" \n"[i==n-1];}
