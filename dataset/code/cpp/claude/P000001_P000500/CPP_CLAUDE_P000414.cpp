#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);double budget;cin>>budget;bool found=false;for(auto&r:recs){istringstream iss(r);string tok,last;while(iss>>tok)last=tok;if(!last.empty()&&stod(last)<=budget){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Flights Found\n";}
