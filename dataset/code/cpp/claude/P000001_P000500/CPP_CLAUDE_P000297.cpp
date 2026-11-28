#include<iostream>
#include<unordered_map>
using namespace std;
int main(){string s;cin>>s;unordered_map<char,int>m={{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000}};int res=0;for(int i=0;i<(int)s.size();i++){if(i+1<(int)s.size()&&m[s[i]]<m[s[i+1]])res-=m[s[i]];else res+=m[s[i]];}cout<<res<<"\n";}
