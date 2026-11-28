#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
int main(){int n;cin>>n;string s;cin>>s;int k;cin>>k;unordered_map<char,int>mp;for(char c:s)mp[c]++;priority_queue<pair<int,char>>pq;for(auto&p:mp)pq.push({p.second,p.first});int res=0;while(!pq.empty()){auto[f,c]=pq.top();pq.pop();int idle=max(0,k-(int)pq.size());res+=f;if(!pq.empty()&&idle>0)res+=idle;}cout<<res<<endl;return 0;}
