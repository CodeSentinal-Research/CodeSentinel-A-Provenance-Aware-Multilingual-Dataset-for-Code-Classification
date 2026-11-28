#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int i=0;i<n;i++)cin>>a[i];priority_queue<int>mx;priority_queue<int,vector<int>,greater<int>>mn;for(int x:a){mx.push(x);mn.push(mx.top());mx.pop();if(mn.size()>mx.size()+1){mx.push(mn.top());mn.pop();}else if(mx.size()>mn.size()){mn.push(mx.top());mx.pop();}if(mn.size()==mx.size())cout<<(mn.top()+mx.top())/2.0<<" ";else cout<<mn.top()<<" ";}cout<<endl;return 0;}
