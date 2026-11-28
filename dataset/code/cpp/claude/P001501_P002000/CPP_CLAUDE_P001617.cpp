#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<long long> buildPrefix(vector<long long>& arr){
        int n=arr.size();
        vector<long long> p(n+1,0);
        for(int i=0;i<n;i++) p[i+1]=p[i]+arr[i];
        return p;
    }
    long long query(vector<long long>& p,int l,int r){return p[r+1]-p[l];}
};
int main(){
    int n;cin>>n;
    vector<long long> arr(n);
    for(auto& x:arr) cin>>x;
    Solution sol;
    auto p=sol.buildPrefix(arr);
    int q;cin>>q;
    while(q--){int l,r;cin>>l>>r;cout<<sol.query(p,l,r)<<"\n";}
}
