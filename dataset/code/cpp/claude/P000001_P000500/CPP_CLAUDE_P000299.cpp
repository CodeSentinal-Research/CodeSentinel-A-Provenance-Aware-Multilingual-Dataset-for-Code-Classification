#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string>res;
void gen(int n,int o,int c,string s){
if(o==n&&c==n){res.push_back(s);return;}
if(o<n)gen(n,o+1,c,s+"(");
if(c<o)gen(n,o,c+1,s+")");
}
int main(){int n;cin>>n;gen(n,0,0,"");for(int i=0;i<(int)res.size();i++)cout<<res[i]<<" \n"[i+1==(int)res.size()];}
