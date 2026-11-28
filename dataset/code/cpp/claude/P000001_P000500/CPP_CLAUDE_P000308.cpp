#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ways(string s){
    vector<int>res;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='*')continue;
        for(int l:ways(s.substr(0,i)))for(int r:ways(s.substr(i+1))){
            if(s[i]=='+')res.push_back(l+r);
            else if(s[i]=='-')res.push_back(l-r);
            else res.push_back(l*r);
        }
    }
    if(res.empty())res.push_back(stoi(s));
    return res;
}
int main(){string e;cin>>e;auto v=ways(e);sort(v.begin(),v.end());for(int i=0;i<(int)v.size();i++)cout<<v[i]<<" \n"[i+1==(int)v.size()];}
