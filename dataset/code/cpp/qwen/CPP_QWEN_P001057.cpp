#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);unordered_map<int,int>mp;for(int i=0;i<n;i++){cin>>a[i];mp[a[i]++;}priority_queue<int,vector<int>,greater<>>pq;for(auto&p:mp)pq.push(p.second);while(k-->0&&!pq.empty()){int f=pq.top();pq.pop();if(f>1)pq.push(f-1);}int res=0;while(!pq.empty())res+=pq.top(),pq.pop();cout<<res<<endl;return 0;}
