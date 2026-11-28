#include<iostream>
#include<string>
#include<sstream>
#include<unordered_set>
using namespace std;
int main(){string text,broken;getline(cin,text);cin>>broken;unordered_set<char>bs(broken.begin(),broken.end());int cnt=0;istringstream iss(text);string w;while(iss>>w){bool ok=true;for(char c:w)if(bs.count(c)){ok=false;break;}if(ok)cnt++;}cout<<cnt<<"\n";}
