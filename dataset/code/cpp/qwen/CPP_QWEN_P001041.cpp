#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>q(n),w(n);for(int i=0;i<n;i++)cin>>q[i];for(int i=0;i<n;i++)cin>>w[i];vector<int>idx(n);for(int i=0;i<n;i++)idx[i]=i;sort(idx.begin(),idx.end(),[&](int a,int b){return (double)w[a]/q[a]<(double)w[b]/q[b];});priority_queue<int>pq;long long sum=0;double res=1e18;for(int i:idx){pq.push(q[i]);sum+=q[i];if(pq.size()>k)sum-=pq.top(),pq.pop();if(pq.size()==k)res=min(res,(double)sum*w[i]/q[i]);}cout<<res<<endl;return 0;}
