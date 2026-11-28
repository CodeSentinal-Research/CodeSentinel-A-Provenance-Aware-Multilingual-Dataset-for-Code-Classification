#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;priority_queue<pair<long long,pair<int,int>>>pq;for(int i=0;i<n;i++){int x,y;cin>>x>>y;long long d=1LL*x*x+1LL*y*y;pq.push({d,{x,y}});if(pq.size()>k)pq.pop();}while(!pq.empty()){cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;pq.pop();}return 0;}
