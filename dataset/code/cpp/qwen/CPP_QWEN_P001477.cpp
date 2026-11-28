#include<bits/stdc++.h>
using namespace std;
int main(){string s,t;getline(cin,s);getline(cin,t);auto build=[](string s){string r="";for(char c:s){if(c=='#'){if(!r.empty())r.pop_back();}else r+=c;}return r;};cout<<(build(s)==build(t)?"true":"false")<<endl;return 0;}
