#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
int main(){int n;cin>>n;vector<int>res(n,0);stack<int>stk;int prev=0;
string log;getline(cin,log);
for(int i=0;i<n;i++){getline(cin,log);
    int c1=log.find(':'),c2=log.rfind(':');
    int fid=stoi(log.substr(0,c1));string typ=log.substr(c1+1,c2-c1-1);int t=stoi(log.substr(c2+1));
    if(typ=="start"){if(!stk.empty())res[stk.top()]+=t-prev;stk.push(fid);prev=t;}
    else{res[stk.top()]+=t-prev+1;stk.pop();prev=t+1;}
}for(int i=0;i<n;i++)cout<<res[i]<<" \n"[i==n-1];}
