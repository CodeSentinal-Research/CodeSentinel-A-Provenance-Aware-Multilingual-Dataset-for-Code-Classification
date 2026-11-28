#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);string dest;getline(cin,dest);bool found=false;for(auto&r:recs){istringstream iss(r);string f1,f2;if((iss>>f1>>f2)&&f2==dest){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Flights Found\n";}
