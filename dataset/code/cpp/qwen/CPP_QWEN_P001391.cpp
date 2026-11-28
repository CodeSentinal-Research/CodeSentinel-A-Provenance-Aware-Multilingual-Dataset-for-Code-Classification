#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<int,string,int>>emp;for(int i=0;i<n;i++){int id;string name;int dept;cin>>id>>name>>dept;emp.push_back({id,name,dept});}int tid;cin>>tid;for(auto&[id,name,dept]:emp)if(id==tid){cout<<id<<" "<<name<<" "<<dept<<endl;return 0;}cout<<"Record Not Found"<<endl;return 0;}
