#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){int r,c;cin>>r>>c;vector<set<int>>rows(r);for(int i=0;i<r;i++){for(int j=0;j<c;j++){int x;cin>>x;rows[i].insert(x);}}set<int>common=rows[0];for(int i=1;i<r;i++){set<int>tmp;for(int x:common)if(rows[i].count(x))tmp.insert(x);common=tmp;}bool first=true;for(int x:common){if(!first)cout<<" ";cout<<x;first=false;}cout<<"\n";}
