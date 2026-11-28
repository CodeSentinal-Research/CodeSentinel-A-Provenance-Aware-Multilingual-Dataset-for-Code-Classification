#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<string,string,string>>veh;for(int i=0;i<n;i++){string reg,make,model;cin>>reg>>make>>model;veh.push_back({reg,make,model});}string treg;cin>>treg;for(auto&[reg,make,model]:veh)if(reg==treg){cout<<reg<<" "<<make<<" "<<model<<endl;return 0;}cout<<"Vehicle Not Found"<<endl;return 0;}
