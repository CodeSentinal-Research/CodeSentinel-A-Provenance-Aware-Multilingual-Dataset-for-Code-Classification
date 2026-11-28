#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];priority_queue<int>pq;for(int x:a){pq.push(x);if(pq.size()>k)pq.pop();}while(!pq.empty()){cout<<pq.top()<<" ";pq.pop();}cout<<endl;return 0;}
