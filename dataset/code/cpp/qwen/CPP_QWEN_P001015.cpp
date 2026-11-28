#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);unordered_map<int,int>mp;for(int i=0;i<n;i++){cin>>a[i];mp[a[i]++;}priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;for(auto&p:mp){pq.push({p.second,p.first});if(pq.size()>k)pq.pop();}while(!pq.empty()){cout<<pq.top().second<<" ";pq.pop();}cout<<endl;return 0;}
