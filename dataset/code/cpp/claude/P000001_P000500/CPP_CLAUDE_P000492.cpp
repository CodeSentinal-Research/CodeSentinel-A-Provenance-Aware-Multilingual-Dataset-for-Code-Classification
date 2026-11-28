#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main(){string path;getline(cin,path);vector<string>stk;stringstream ss(path);string p;while(getline(ss,p,'/')){if(p==".."&&!stk.empty())stk.pop_back();else if(!p.empty()&&p!=".")stk.push_back(p);}cout<<"/";for(int i=0;i<(int)stk.size();i++){if(i)cout<<"/";cout<<stk[i];}cout<<"\n";}
