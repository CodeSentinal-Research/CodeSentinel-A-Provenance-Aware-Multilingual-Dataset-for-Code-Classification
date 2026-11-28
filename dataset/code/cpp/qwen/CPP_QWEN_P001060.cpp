#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];priority_queue<int,vector<int>,greater<>>pq;for(int i=0;i<n;i++){pq.push(a[i]);if(pq.size()>k+1){cout<<pq.top()<<" ";pq.pop();}}while(!pq.empty()){cout<<pq.top()<<" ";pq.pop();}cout<<endl;return 0;}
