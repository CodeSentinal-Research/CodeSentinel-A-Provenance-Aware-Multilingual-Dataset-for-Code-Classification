#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){int n;cin>>n;vector<int>p(n);for(int i=0;i<n;i++)cin>>p[i];set<int>nodes;for(int i=0;i<n;i++)nodes.insert(i);for(int i=1;i<n;i++)if(!nodes.count(p[i])||p[i]>=i){cout<<"NO"<<endl;return 0;}cout<<"YES"<<endl;return 0;}
