/* P000794: Maximum Size Subarray Sum Equals K */
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;vector<long long>a(n);for(auto&v:a)cin>>v;long long k;cin>>k;
    unordered_map<long long,int>pre;pre[0]=-1;long long s=0;int best=0;
    for(int i=0;i<n;i++){
        s+=a[i];
        auto it=pre.find(s-k);
        if(it!=pre.end()) best=max(best,i-it->second);
        pre.emplace(s,i);
    }
    cout<<best<<"\n";
}
