#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<int,string,int>>htl;for(int i=0;i<n;i++){int id;string name;int stars;cin>>id>>name>>stars;htl.push_back({id,name,stars});}int tid;cin>>tid;for(auto&[id,name,stars]:htl)if(id==tid){cout<<id<<" "<<name<<" "<<stars<<endl;return 0;}cout<<"Hotel Not Found"<<endl;return 0;}
