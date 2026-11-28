#include<iostream>
#include<queue>
using namespace std;
int main(){int n;cin>>n;queue<int>q;while(n--){string cmd;cin>>cmd;if(cmd=="push"){int x;cin>>x;q.push(x);for(int i=0;i<(int)q.size()-1;i++){q.push(q.front());q.pop();}}else if(cmd=="pop"){cout<<q.front()<<"\n";q.pop();}else if(cmd=="top")cout<<q.front()<<"\n";else cout<<(q.empty()?"true":"false")<<"\n";}}
