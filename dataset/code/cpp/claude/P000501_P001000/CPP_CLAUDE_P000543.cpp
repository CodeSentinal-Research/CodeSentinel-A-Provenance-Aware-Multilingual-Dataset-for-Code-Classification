/* P000543: Data Stream as Disjoint Intervals */
#include<iostream>
#include<set>
#include<string>
using namespace std;
set<pair<int,int>> ivs;
void add(int v){
    int nl=v,nh=v;
    vector<set<pair<int,int>>::iterator> rem;
    auto it=ivs.lower_bound({v-1,v-1});
    if(it!=ivs.begin()){--it;if(it->second<v-1)++it;}
    while(it!=ivs.end()&&it->first<=v+1){
        nl=min(nl,it->first);nh=max(nh,it->second);rem.push_back(it);++it;}
    for(auto&r:rem)ivs.erase(r);
    ivs.insert({nl,nh});
}
int main(){int q;cin>>q;string cmd;
while(q--){cin>>cmd;if(cmd=="addNum"){int v;cin>>v;add(v);}
    else{for(auto&[a,b]:ivs)cout<<"["<<a<<","<<b<<"] ";cout<<"\n";}}}
