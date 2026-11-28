#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);string q;getline(cin,q);bool found=false;for(auto&r:recs){istringstream iss(r);string f;for(int k=0;k<=1;k++)iss>>f;if(f==q){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Accounts Found\n";}
