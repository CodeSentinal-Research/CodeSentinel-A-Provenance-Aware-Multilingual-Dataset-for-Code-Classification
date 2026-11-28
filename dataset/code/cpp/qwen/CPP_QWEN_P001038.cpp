#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>cap(n),prof(n);for(int i=0;i<n;i++)cin>>cap[i];for(int i=0;i<n;i++)cin>>prof[i];int w;cin>>w;vector<int>idx(n);for(int i=0;i<n;i++)idx[i]=i;sort(idx.begin(),idx.end(),[&](int a,int b){return cap[a]<cap[b];});priority_queue<int>pq;int j=0;for(int i=0;i<k;i++){while(j<n&&cap[idx[j]]<=w){pq.push(prof[idx[j]]);j++;}if(!pq.empty()){w+=pq.top();pq.pop();}}cout<<w<<endl;return 0;}
