#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;vector<tuple<int,int,int>>j(n);int md=0;for(auto&[id,d,p]:j){cin>>id>>d>>p;md=max(md,d);}sort(j.begin(),j.end(),[](auto&a,auto&b){return get<2>(a)>get<2>(b);});vector<int>slot(md+1,-1);int cnt=0,prof=0;for(auto&[id,d,p]:j){for(int t=d;t>0;t--){if(slot[t]==-1){slot[t]=id;cnt++;prof+=p;break;}}}cout<<cnt<<" "<<prof<<"\n";}
