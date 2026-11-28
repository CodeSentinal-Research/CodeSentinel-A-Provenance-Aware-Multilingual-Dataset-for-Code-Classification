#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);priority_queue<int>mx;int mn=1e9;for(int i=0;i<n;i++){cin>>a[i];if(a[i]%2)mx.push(a[i]*2),mn=min(mn,a[i]*2);else mx.push(a[i]),mn=min(mn,a[i]);}int res=1e9;while(1){res=min(res,mx.top()-mn);int v=mx.top();mx.pop();if(v%2==0){v/=2;mx.push(v);mn=min(mn,v);}else break;}cout<<res<<endl;return 0;}
