#include<iostream>
#include<string>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>files(n);for(auto&f:files)getline(cin,f);string ext;getline(cin,ext);bool found=false;for(auto&f:files){if(f.size()>ext.size()+1&&f.substr(f.size()-ext.size()-1)=="."+ext){cout<<f<<"\n";found=true;}}if(!found)cout<<"No Records Found\n";}
