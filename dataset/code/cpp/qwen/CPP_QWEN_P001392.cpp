#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<int,string,float>>stu;for(int i=0;i<n;i++){int id;string name;float gpa;cin>>id>>name>>gpa;stu.push_back({id,name,gpa});}int tid;cin>>tid;for(auto&[id,name,gpa]:stu)if(id==tid){cout<<id<<" "<<name<<" "<<gpa<<endl;return 0;}cout<<"Record Not Found"<<endl;return 0;}
