#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){int n;cin>>n;cin.ignore();vector<string>strs(n);for(auto&s:strs)getline(cin,s);string enc="";for(auto&s:strs)enc+=to_string(s.size())+"#"+s;cout<<enc<<"\n";int i=0;while(i<(int)enc.size()){int j=enc.find('#',i),l=stoi(enc.substr(i,j-i));cout<<enc.substr(j+1,l)<<" ";i=j+1+l;}cout<<"\n";}
