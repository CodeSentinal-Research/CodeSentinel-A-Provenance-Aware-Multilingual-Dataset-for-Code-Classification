#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);string q;getline(cin,q);for(auto&r:recs){istringstream iss(r);string f;for(int k=0;k<=0;k++)if(!(iss>>f))break;if(f==q){cout<<r<<"\n";return 0;}}cout<<"Member Not Found\n";}
