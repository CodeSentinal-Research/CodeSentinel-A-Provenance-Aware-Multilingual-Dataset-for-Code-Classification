#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
vector<int>split(const string&s){vector<int>v;stringstream ss(s);string t;while(getline(ss,t,'.'))v.push_back(stoi(t));return v;}
int main(){string a,b;cin>>a>>b;auto pa=split(a),pb=split(b);int n=max(pa.size(),pb.size());
for(int i=0;i<n;i++){int va=i<(int)pa.size()?pa[i]:0,vb=i<(int)pb.size()?pb[i]:0;if(va<vb){cout<<-1<<"\n";return 0;}if(va>vb){cout<<1<<"\n";return 0;}}cout<<0<<"\n";}
