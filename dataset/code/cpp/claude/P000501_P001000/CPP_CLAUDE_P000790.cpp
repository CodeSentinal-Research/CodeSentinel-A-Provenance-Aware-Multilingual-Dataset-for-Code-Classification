#include<iostream>
#include<unordered_map>
using namespace std;
int main(){int n;cin>>n;int a[n];for(auto&v:a)cin>>v;int k;cin>>k;
unordered_map<int,int>seen;seen[0]=-1;int s=0;
for(int i=0;i<n;i++){s=((s+a[i])%k+k)%k;if(seen.count(s)&&i-seen[s]>=2){cout<<"true\n";return 0;}if(!seen.count(s))seen[s]=i;}
cout<<"false\n";}
