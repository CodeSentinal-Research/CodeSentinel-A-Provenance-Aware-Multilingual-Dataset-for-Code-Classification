#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<int,string,string>>pat;for(int i=0;i<n;i++){int id;string name,blood;cin>>id>>name>>blood;pat.push_back({id,name,blood});}int tid;cin>>tid;for(auto&[id,name,blood]:pat)if(id==tid){cout<<id<<" "<<name<<" "<<blood<<endl;return 0;}cout<<"Patient Not Found"<<endl;return 0;}
