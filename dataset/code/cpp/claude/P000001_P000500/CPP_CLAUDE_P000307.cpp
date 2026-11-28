#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>
#include<vector>
using namespace std;
bool valid(const string&s){int c=0;for(char x:s){if(x=='(')c++;else if(x==')')if(--c<0)return false;}return c==0;}
int main(){string s;cin>>s;
unordered_set<string>vis;queue<string>q;q.push(s);vis.insert(s);
vector<string>res;bool found=false;
while(!q.empty()){
    string cur=q.front();q.pop();
    if(valid(cur)){res.push_back(cur);found=true;}
    if(found)continue;
    for(int i=0;i<(int)cur.size();i++){
        if(cur[i]!='('&&cur[i]!=')')continue;
        string nxt=cur.substr(0,i)+cur.substr(i+1);
        if(!vis.count(nxt)){vis.insert(nxt);q.push(nxt);}
    }
}
for(auto&r:res)cout<<r<<"\n";}
