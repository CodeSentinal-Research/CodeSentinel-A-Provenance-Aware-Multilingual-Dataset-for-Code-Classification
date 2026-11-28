#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);string kw;getline(cin,kw);bool found=false;for(auto&r:recs)if(r.find(kw)!=string::npos){cout<<r<<"\n";found=true;}if(!found)cout<<"No Records Found\n";}
