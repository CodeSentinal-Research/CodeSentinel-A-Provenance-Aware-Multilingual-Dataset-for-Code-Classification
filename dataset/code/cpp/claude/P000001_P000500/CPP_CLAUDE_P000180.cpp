#include <vector>
class Solution {
public:
    std::vector<int> majorityElementNBy3(std::vector<int>& nums) {
        int c1=0,c2=1,cnt1=0,cnt2=0;
        for (int x : nums) {
            if (x==c1) cnt1++;
            else if (x==c2) cnt2++;
            else if (cnt1==0) { c1=x; cnt1=1; }
            else if (cnt2==0) { c2=x; cnt2=1; }
            else { cnt1--; cnt2--; }
        }
        int fc1=0,fc2=0,threshold=nums.size()/3;
        for (int x : nums) { if(x==c1) fc1++; else if(x==c2) fc2++; }
        std::vector<int> res;
        if (fc1>threshold) res.push_back(c1);
        if (fc2>threshold) res.push_back(c2);
        return res;
    }
};
