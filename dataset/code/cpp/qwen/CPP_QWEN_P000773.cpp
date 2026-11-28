#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

void parse(const string& expr, vector<long long>& nums, vector<char>& ops) {
    long long currentNum = 0;
    for (char c : expr) {
        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else {
            nums.push_back(currentNum);
            ops.push_back(c);
            currentNum = 0;
        }
    }
    nums.push_back(currentNum);
}

unordered_map<long long, int> solve(const vector<long long>& nums, const vector<char>& ops, int i, int j) {
    unordered_map<long long, int> res;
    if (i == j) {
        res[nums[i]] = 1;
        return res;
    }
    
    for (int k = i; k < j; ++k) {
        auto leftMap = solve(nums, ops, i, k);
        auto rightMap = solve(nums, ops, k + 1, j);
        char op = ops[k];
        
        for (auto& l : leftMap) {
            for (auto& r : rightMap) {
                long long val = 0;
                if (op == '+') val = l.first + r.first;
                else if (op == '-') val = l.first - r.first;
                else if (op == '*') val = l.first * r.first;
                res[val] += l.second * r.second;
            }
        }
    }
    return res;
}

int main() {
    string expr;
    cin >> expr;
    vector<long long> nums;
    vector<char> ops;
    parse(expr, nums, ops);
    
    auto resMap = solve(nums, ops, 0, nums.size() - 1);
    
    long long maxVal = LLONG_MIN;
    int count = 0;
    for (auto& p : resMap) {
        if (p.first > maxVal) {
            maxVal = p.first;
            count = p.second;
        }
    }
    cout << count << endl;
    return 0;
}
