#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<sstream>
using namespace std;
string s;unordered_set<string>ws;vector<string>res;
void bt(int i,string path){
    if(i==(int)s.size()){res.push_back(path);return;}
    for(int j=i+1;j<=(int)s.size();j++){
        string w=s.substr(i,j-i);
        if(ws.count(w))bt(j,path.empty()?w:path+" "+w);
    }
}
int main(){cin>>s;cin.ignore();string line;getline(cin,line);istringstream iss(line);string w;while(iss>>w)ws.insert(w);bt(0,"");for(auto&r:res)cout<<r<<"\n";}
