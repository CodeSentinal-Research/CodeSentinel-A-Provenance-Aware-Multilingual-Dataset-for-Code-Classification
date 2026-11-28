#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int n; cin>>n;
    unordered_map<int,int> freq,first,last;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        freq[x]++;
        if(!first.count(x)) first[x]=i;
        last[x]=i;
    }
    int deg=0;
    for(auto&p:freq) deg=max(deg,p.second);
    int res=n;
    for(auto&p:freq)
        if(p.second==deg) res=min(res,last[p.first]-first[p.first]+1);
    cout<<res<<"\n";
}
