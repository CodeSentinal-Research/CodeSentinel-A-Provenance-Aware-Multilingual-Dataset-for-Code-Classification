#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>recs(n);for(auto&r:recs)getline(cin,r);bool found=false;for(auto&r:recs){string l=r;transform(l.begin(),l.end(),l.begin(),::tolower);if(l.find("active")!=string::npos){cout<<r<<"\n";found=true;}}if(!found)cout<<"No Records Found\n";}
