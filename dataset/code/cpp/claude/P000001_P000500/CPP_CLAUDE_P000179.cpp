#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_map<int,int> order;
        for (int i = 0; i < (int)arr2.size(); i++) order[arr2[i]] = i;
        std::vector<int> res = arr1;
        std::sort(res.begin(), res.end(), [&](int a, int b){
            bool ha = order.count(a), hb = order.count(b);
            if (ha && hb) return order[a] < order[b];
            if (ha) return true;
            if (hb) return false;
            return a < b;
        });
        return res;
    }
};
