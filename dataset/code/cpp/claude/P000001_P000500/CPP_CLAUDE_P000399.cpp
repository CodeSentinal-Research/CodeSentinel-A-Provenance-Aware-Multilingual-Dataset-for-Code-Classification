#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);int yr;cin>>yr;bool found=false;for(auto&r:recs){istringstream iss(r);string tok;int y=0;while(iss>>tok){try{y=stoi(tok);}catch(...){}}if(y>yr){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Records Found\n";}
