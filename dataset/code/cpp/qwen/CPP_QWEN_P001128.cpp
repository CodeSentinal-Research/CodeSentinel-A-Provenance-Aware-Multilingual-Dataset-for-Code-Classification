#include<bits/stdc++.h>
using namespace std;
int p[100005];int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){int n;cin>>n;unordered_map<string,vector<int>>email_to_ids;for(int i=0;i<n;i++){string name;int sz;cin>>name>>sz;for(int j=0;j<sz;j++){string email;cin>>email;email_to_ids[email].push_back(i);}}for(int i=0;i<n;i++)p[i]=i;for(auto&[e,ids]:email_to_ids)for(int i=1;i<ids.size();i++)p[f(ids[i])]=f(ids[0]);unordered_map<int,vector<string>>res;for(auto&[e,ids]:email_to_ids)res[f(ids[0])].push_back(e);for(auto&[i,emails]:res){sort(emails.begin(),emails.end());cout<<emails[0];for(int j=1;j<emails.size();j++)cout<<" "<<emails[j];cout<<endl;}return 0;}
