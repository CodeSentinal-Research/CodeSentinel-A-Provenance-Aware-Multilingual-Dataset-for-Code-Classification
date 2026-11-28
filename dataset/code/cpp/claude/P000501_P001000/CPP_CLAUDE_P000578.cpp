/* P000578: Binary Tree Top View */
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main(){string line;getline(cin,line);istringstream iss(line);string tok;
    vector<int>val;vector<bool>has;
    while(iss>>tok){if(tok=="null"){has.push_back(false);val.push_back(0);}else{has.push_back(true);val.push_back(stoi(tok));}}
    int n=val.size();if(n==0||!has[0])return 0;
    queue<tuple<int,int,int>>q;q.push({0,0,0});map<int,int>top;
    while(!q.empty()){auto[idx,lev,hd]=q.front();q.pop();
        if(idx>=n||!has[idx])continue;
        if(top.find(hd)==top.end())top[hd]=val[idx];
        if(2*idx+1<n)q.push({2*idx+1,lev+1,hd-1});
        if(2*idx+2<n)q.push({2*idx+2,lev+1,hd+1});}
    for(auto&[h,v]:top)cout<<v<<" ";cout<<"\n";}
