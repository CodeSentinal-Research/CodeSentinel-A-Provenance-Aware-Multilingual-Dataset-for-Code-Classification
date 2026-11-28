#include<iostream>
#include<unordered_map>
using namespace std;
int main(){string s,t;cin>>s>>t;if(s.size()!=t.size()){cout<<"No\n";return 0;}unordered_map<char,char>ms,mt;for(int i=0;i<(int)s.size();i++){if(!ms.count(s[i]))ms[s[i]]=t[i];if(!mt.count(t[i]))mt[t[i]]=s[i];if(ms[s[i]]!=t[i]||mt[t[i]]!=s[i]){cout<<"No\n";return 0;}}cout<<"Yes\n";}
