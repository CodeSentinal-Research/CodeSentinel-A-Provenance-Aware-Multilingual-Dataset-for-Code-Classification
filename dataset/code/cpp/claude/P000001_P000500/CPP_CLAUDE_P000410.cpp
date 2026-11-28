#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);string sfx;getline(cin,sfx);bool found=false;for(auto&r:recs){string nm=r.substr(0,r.find(' '));if(nm.size()>=sfx.size()&&nm.substr(nm.size()-sfx.size())==sfx){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Products Found\n";}
