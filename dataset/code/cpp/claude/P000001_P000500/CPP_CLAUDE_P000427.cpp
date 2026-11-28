#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);double mp;cin>>mp;bool found=false;for(auto&r:recs){istringstream iss(r);string tok,last;while(iss>>tok)last=tok;if(!last.empty()&&stod(last)>=mp){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Products Found\n";}
