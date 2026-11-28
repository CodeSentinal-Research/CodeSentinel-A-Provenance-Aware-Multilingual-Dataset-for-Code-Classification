#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    long long knapsack01(vector<int>& wt, vector<int>& val, int W){
        int n=wt.size();
        vector<long long> dp(W+1,0);
        for(int i=0;i<n;i++)
            for(int j=W;j>=wt[i];j--)
                dp[j]=max(dp[j], dp[j-wt[i]]+(long long)val[i]);
        return dp[W];
    }
};
int main(){
    int n,W;cin>>n>>W;
    vector<int> wt(n),val(n);
    for(auto& x:wt) cin>>x;
    for(auto& x:val) cin>>x;
    cout<<Solution().knapsack01(wt,val,W)<<"\n";
}
