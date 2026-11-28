#include<bits/stdc++.h>
using namespace std;
int main(){int n;cin>>n;unordered_set<string>dict;for(int i=0;i<n;i++){string s;cin>>s;dict.insert(s);}string bw,ew;cin>>bw>>ew;if(!dict.count(ew)){cout<<0<<endl;return 0;}queue<pair<string,int>>q;q.push({bw,1});while(!q.empty()){auto[w,s]=q.front();q.pop();if(w==ew){cout<<s<<endl;return 0;}for(int i=0;i<w.size();i++){char o=w[i];for(char c='a';c<='z';c++){if(c==o)continue;w[i]=c;if(dict.count(w)){dict.erase(w);q.push({w,s+1});}}w[i]=o;}}cout<<0<<endl;return 0;}
