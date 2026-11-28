#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<string,string,string>>cust;for(int i=0;i<n;i++){string name,mob,email;cin>>name>>mob>>email;cust.push_back({name,mob,email});}string tmob;cin>>tmob;for(auto&[name,mob,email]:cust)if(mob==tmob){cout<<name<<" "<<mob<<" "<<email<<endl;return 0;}cout<<"Customer Not Found"<<endl;return 0;}
