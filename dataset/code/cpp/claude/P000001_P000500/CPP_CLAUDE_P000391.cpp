#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);double t;cin>>t;bool found=false;for(auto&r:recs){istringstream iss(r);string tok;double gpa=0;while(iss>>tok){try{gpa=stod(tok);}catch(...){}}if(gpa>=t){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Records Found\n";}
