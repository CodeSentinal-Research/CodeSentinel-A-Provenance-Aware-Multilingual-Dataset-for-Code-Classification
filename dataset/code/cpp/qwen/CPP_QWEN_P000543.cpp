#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class SummaryRanges {
    map<int, int> intervals;
public:
    void addNum(int val) {
        auto it = intervals.lower_bound(val);
        if (it != intervals.end() && it->first == val) return;
        int l = val, r = val;
        if (it != intervals.end() && it->first == val + 1) { r = it->second; it = intervals.erase(it); }
        if (it != intervals.begin() && prev(it)->second >= val - 1) { prev(it)->second = max(prev(it)->second, r); return; }
        intervals[l] = r;
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& p : intervals) res.push_back({p.first, p.second});
        return res;
    }
};

int main() {
    int q_num; cin >> q_num;
    SummaryRanges sr;
    while(q_num--) {
        string op; cin >> op;
        if(op == "addNum") { int val; cin >> val; sr.addNum(val); }
        else if(op == "getIntervals") {
            auto iv = sr.getIntervals();
            cout << "[";
            for(auto& v : iv) cout << "[" << v[0] << "," << v[1] << "]";
            cout << "] ";
        }
    }
    cout << endl;
    return 0;
}
