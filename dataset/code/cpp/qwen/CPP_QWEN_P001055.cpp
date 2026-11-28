#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int target,startFuel,n;cin>>target>>startFuel>>n;vector<pair<int,int>>stations(n);for(int i=0;i<n;i++)cin>>stations[i].first>>stations[i].second;priority_queue<int>pq;int res=0,cur=0;for(int i=0;i<=n;i++){int dist=(i==n?target:stations[i].first)-cur;startFuel-=dist;while(startFuel<0&&!pq.empty()){startFuel+=pq.top();pq.pop();res++;}if(startFuel<0){cout<<-1<<endl;return 0;}if(i<n)pq.push(stations[i].second);cur=(i==n?target:stations[i].first);}cout<<res<<endl;return 0;}
