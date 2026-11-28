#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
int main(){
    string s,line;cin>>s;cin.ignore();getline(cin,line);
    unordered_set<string>ws;istringstream iss(line);string w;
    while(iss>>w)ws.insert(w);
    int n=s.size();vector<bool>dp(n+1,false);dp[0]=true;
    for(int i=1;i<=n;i++)for(int j=0;j<i;j++)if(dp[j]&&ws.count(s.substr(j,i-j))){dp[i]=true;break;}
    cout<<(dp[n]?"Yes":"No")<<"\n";
}
