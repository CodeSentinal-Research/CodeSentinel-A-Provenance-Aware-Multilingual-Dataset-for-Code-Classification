#include<iostream>
#include<string>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);string pfx;getline(cin,pfx);bool found=false;for(auto&r:recs){string nm=r.substr(0,r.find(" "));if(nm.substr(0,pfx.size())==pfx){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Records Found\n";}
