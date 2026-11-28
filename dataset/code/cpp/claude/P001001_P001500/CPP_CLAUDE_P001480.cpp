#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    pair<int,int> twoPointer(vector<long long>& arr, long long target){
        int lo=0,hi=arr.size()-1;
        while(lo<hi){
            long long s=arr[lo]+arr[hi];
            if(s==target) return {lo,hi};
            else if(s<target) lo++;
            else hi--;
        }
        return {-1,-1};
    }
};
int main(){
    int n;long long t;cin>>n>>t;
    vector<long long> arr(n);
    for(auto& x:arr) cin>>x;
    auto [a,b]=Solution().twoPointer(arr,t);
    cout<<a<<" "<<b<<"\n";
}
