#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){int n,k;cin>>n>>k;vector<int>s(n),e(n);for(int i=0;i<n;i++)cin>>s[i];for(int i=0;i<n;i++)cin>>e[i];vector<int>idx(n);for(int i=0;i<n;i++)idx[i]=i;sort(idx.begin(),idx.end(),[&](int a,int b){return e[a]>e[b];});priority_queue<int,vector<int>,greater<>>pq;long long sum=0,res=0;for(int i:idx){pq.push(s[i]);sum+=s[i];if(pq.size()>k){sum-=pq.top();pq.pop();}res=max(res,sum*e[i]);}cout<<res<<endl;return 0;}
