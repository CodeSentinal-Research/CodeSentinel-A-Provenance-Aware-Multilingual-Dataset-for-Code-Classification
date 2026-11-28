#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){int q;cin>>q;priority_queue<int>pq;while(q--){string op;cin>>op;if(op=="push"){int x;cin>>x;pq.push(x);}else if(op=="pop"){if(!pq.empty())pq.pop();}else if(op=="top"){cout<<(pq.empty()?-1:pq.top())<<" ";}else if(op=="empty"){cout<<(pq.empty()?"true":"false")<<" ";}}cout<<endl;return 0;}
