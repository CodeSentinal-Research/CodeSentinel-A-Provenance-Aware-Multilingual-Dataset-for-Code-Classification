/* P000791: Longest Subarray with Sum K */
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;vector<long long>a(n);for(auto&v:a)cin>>v;long long k;cin>>k;
    unordered_map<long long,int>pre;pre[0]=-1;long long s=0;int best=0;
    for(int i=0;i<n;i++){
        s+=a[i];
        if(pre.count(s-k)) best=max(best,i-pre[s-k]);
        if(!pre.count(s)) pre[s]=i;
    }
    cout<<best<<"\n";
}
