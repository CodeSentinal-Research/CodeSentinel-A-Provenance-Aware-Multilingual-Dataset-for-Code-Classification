#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n;cin>>n;vector<int>h(n);for(int i=0;i<n;i++)cin>>h[i];int b,l;cin>>b>>l;priority_queue<int>pq;int res=0;for(int i=1;i<n;i++){int diff=h[i]-h[i-1];if(diff>0){if(l>0)l--;else if(b>=diff){b-=diff;pq.push(diff);}else{if(!pq.empty()&&pq.top()>diff){b+=pq.top()-diff;pq.pop();pq.push(diff);b-=diff;}else break;}}res=i;}cout<<res<<endl;return 0;}
