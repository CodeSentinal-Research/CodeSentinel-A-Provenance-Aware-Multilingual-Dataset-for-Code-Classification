#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    long long rob(vector<long long>& nums){
        int n=nums.size();
        if(n==1) return nums[0];
        long long p2=nums[0], p1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){long long c=max(p1,p2+nums[i]);p2=p1;p1=c;}
        return p1;
    }
};
int main(){
    int n;cin>>n;
    vector<long long> nums(n);
    for(auto& x:nums) cin>>x;
    cout<<Solution().rob(nums)<<"\n";
}
