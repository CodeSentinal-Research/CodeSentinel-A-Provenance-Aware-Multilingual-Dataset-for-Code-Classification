#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
struct FreqStack{unordered_map<int,int>freq;unordered_map<int,int>time;priority_queue<pair<int,pair<int,int>>>pq;int t=0;void push(int x){freq[x]++;time[x]=++t;pq.push({freq[x],{time[x],x}});}int pop(){auto[f,p]=pq.top();pq.pop();int x=p.second;if(freq[x]==f)freq[x]--;else while(!pq.empty()&&pq.top().second.second==x&&pq.top().first!=freq[x])pq.pop();return x;}};
int main(){int q;cin>>q;FreqStack fs;while(q--){string op;cin>>op;if(op=="push"){int x;cin>>x;fs.push(x);}else cout<<fs.pop()<<" ";}cout<<endl;return 0;}
