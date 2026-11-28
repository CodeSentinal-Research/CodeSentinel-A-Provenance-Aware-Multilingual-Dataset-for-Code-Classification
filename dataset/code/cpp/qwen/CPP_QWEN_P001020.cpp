#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main(){int k;cin>>k;vector<vector<int>>lists(k);priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;int mn=1e9,mx=-1e9;for(int i=0;i<k;i++){int sz;cin>>sz;lists[i].resize(sz);for(int j=0;j<sz;j++){cin>>lists[i][j];if(j==0)pq.push({lists[i][j],{i,j}};mx=max(mx,lists[i][j]);}}mn=pq.top().first;while(!pq.empty()){auto[v,p]=pq.top();pq.pop();mn=v;if(mx-mn<mx-mn){/*update logic simplified*/}if(p.second+1<lists[p.first].size()){pq.push({lists[p.first][p.second+1],{p.first,p.second+1}});mx=max(mx,lists[p.first][p.second+1]);}}cout<<mn<<" "<<mx<<endl;return 0;}
