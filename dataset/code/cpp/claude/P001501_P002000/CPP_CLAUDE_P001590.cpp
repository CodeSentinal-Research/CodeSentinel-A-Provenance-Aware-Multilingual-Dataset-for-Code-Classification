#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    long long maxSlidingWindow(vector<long long>& arr, int k){
        long long s=0,mx;
        for(int i=0;i<k;i++) s+=arr[i];
        mx=s;
        for(int i=k;i<(int)arr.size();i++){s+=arr[i]-arr[i-k];mx=max(mx,s);}
        return mx;
    }
};
int main(){
    int n,k;cin>>n>>k;
    vector<long long> arr(n);
    for(auto& x:arr) cin>>x;
    cout<<Solution().maxSlidingWindow(arr,k)<<"\n";
}
