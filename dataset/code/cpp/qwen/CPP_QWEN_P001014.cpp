#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int k,n;cin>>k>>n;priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;vector<vector<int>>a(k,vector<int>(n));for(int i=0;i<k;i++)for(int j=0;j<n;j++){cin>>a[i][j];if(j==0)pq.push({a[i][j],{i,j}});}vector<int>res;while(!pq.empty()){auto[v,p]=pq.top();pq.pop();res.push_back(v);if(p.second+1<n)pq.push({a[p.first][p.second+1],{p.first,p.second+1}});}for(int x:res)cout<<x<<" ";cout<<endl;return 0;}
