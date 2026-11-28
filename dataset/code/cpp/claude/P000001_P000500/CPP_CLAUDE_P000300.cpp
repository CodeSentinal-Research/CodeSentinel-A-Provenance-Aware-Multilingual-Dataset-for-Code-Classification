#include<iostream>
#include<vector>
#include<string>
using namespace std;
string keys[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>res;
void bt(string&d,int i,string cur){if(i==(int)d.size()){res.push_back(cur);return;}for(char c:keys[d[i]-'0'])bt(d,i+1,cur+c);}
int main(){string d;cin>>d;if(d.empty()){cout<<"\n";return 0;}bt(d,0,"");for(int i=0;i<(int)res.size();i++)cout<<res[i]<<" \n"[i+1==(int)res.size()];}
