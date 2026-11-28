#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);double lo,hi;cin>>lo>>hi;bool found=false;for(auto&r:recs){istringstream iss(r);string tok;double sal=0;while(iss>>tok){try{sal=stod(tok);}catch(...){}}if(sal>=lo&&sal<=hi){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Records Found\n";}
