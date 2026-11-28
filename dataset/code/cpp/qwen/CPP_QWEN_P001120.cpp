#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;unordered_map<string,vector<string>>adj;for(int i=0;i<n;i++){string u,v;cin>>u>>v;adj[u].push_back(v);}for(auto&p:adj)sort(p.second.begin(),p.second.end(),greater<string>());vector<string>res;stack<string>st;st.push("JFK");while(!st.empty()){string u=st.top();if(!adj[u].empty()){string v=adj[u].back();adj[u].pop_back();st.push(v);}else{res.push_back(u);st.pop();}}reverse(res.begin(),res.end());for(string s:res)cout<<s<<" ";cout<<endl;return 0;}
