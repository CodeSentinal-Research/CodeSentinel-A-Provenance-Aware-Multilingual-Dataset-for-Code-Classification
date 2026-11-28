#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<sstream>
using namespace std;
int main(){string pat,line;cin>>pat;cin.ignore();getline(cin,line);
vector<string>words;istringstream iss(line);string w;while(iss>>w)words.push_back(w);
if(pat.size()!=words.size()){cout<<"No\n";return 0;}
unordered_map<char,string>mp;unordered_map<string,char>mw;
for(int i=0;i<(int)pat.size();i++){
    if(!mp.count(pat[i]))mp[pat[i]]=words[i];
    if(!mw.count(words[i]))mw[words[i]]=pat[i];
    if(mp[pat[i]]!=words[i]||mw[words[i]]!=pat[i]){cout<<"No\n";return 0;}
}
cout<<"Yes\n";}
