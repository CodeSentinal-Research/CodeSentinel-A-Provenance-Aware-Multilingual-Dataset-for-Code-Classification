#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<long long> slidingWindowSum(vector<long long>& arr, int k){
        vector<long long> res;
        long long s=0;
        for(int i=0;i<k;i++) s+=arr[i];
        res.push_back(s);
        for(int i=k;i<(int)arr.size();i++){s+=arr[i]-arr[i-k];res.push_back(s);}
        return res;
    }
};
int main(){
    int n,k;cin>>n>>k;
    vector<long long> arr(n);
    for(auto& x:arr) cin>>x;
    for(auto x:Solution().slidingWindowSum(arr,k)) cout<<x<<"\n";
}
