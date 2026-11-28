#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;vector<tuple<string,string,string>>flt;for(int i=0;i<n;i++){string fno,src,dest;cin>>fno>>src>>dest;flt.push_back({fno,src,dest});}string tfno;cin>>tfno;for(auto&[fno,src,dest]:flt)if(fno==tfno){cout<<fno<<" "<<src<<" "<<dest<<endl;return 0;}cout<<"Flight Not Found"<<endl;return 0;}
