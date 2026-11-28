#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<string,string,string>>trn;for(int i=0;i<n;i++){string tno,src,dest;cin>>tno>>src>>dest;trn.push_back({tno,src,dest});}string ttno;cin>>ttno;for(auto&[tno,src,dest]:trn)if(tno==ttno){cout<<tno<<" "<<src<<" "<<dest<<endl;return 0;}cout<<"Train Not Found"<<endl;return 0;}
