#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdint>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
using namespace std;

//1877. Minimize Maximum Pair Sum in Array



class Solution {

public:

    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int n=nums.size();

        int l=0;

        int r=n-1;

        int ans=-1;

        while(l<r){

            ans=max(ans,nums[l]+nums[r]);

            l++;

            r--;

        }

        return ans;

    }

};