#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
int main(){string s;cin>>s;unordered_map<char,int>mp;for(char c:s)mp[c]++;priority_queue<pair<int,char>>pq;for(auto&p:mp)pq.push({p.second,p.first});string res="";while(!pq.empty()){auto[f,c]=pq.top();pq.pop();if(res.empty()||res.back()!=c){res+=c;if(f>1)pq.push({f-1,c});}else{if(pq.empty()){cout<<"IMPOSSIBLE"<<endl;return 0;}auto[f2,c2]=pq.top();pq.pop();res+=c2;if(f2>1)pq.push({f2-1,c2});pq.push({f,c});}}cout<<res<<endl;return 0;}
