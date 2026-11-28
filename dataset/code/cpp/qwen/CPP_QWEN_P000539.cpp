#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class FirstUnique {
    unordered_map<int, int> count;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) { for (int x : nums) add(x); }
    int showFirstUnique() { while (!q.empty() && count[q.front()] > 1) q.pop(); return q.empty() ? -1 : q.front(); }
    void add(int value) { count[value]++; q.push(value); }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    FirstUnique fu(nums);
    int q_num; cin >> q_num;
    while(q_num--) {
        string op; cin >> op;
        if(op == "showFirstUnique") cout << fu.showFirstUnique() << " ";
        else if(op == "add") { int x; cin >> x; fu.add(x); }
    }
    cout << endl;
    return 0;
}
