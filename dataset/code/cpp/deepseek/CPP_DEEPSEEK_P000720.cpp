#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addOperators(string num, int target, int* return_value) {
        vector<int> ans;
        dfs(num, target, 0, 0, 0, "", return_value, ans);
        return ans;
    }

private:
    void dfs(string num, int target, long current, long previous, long intermediate, string expression, int* return_value, vector<int>& ans) {
        if (num.size() == 0 && current == target) {
            if (*return_value <= 10) {
                ans.push_back(stoi(expression));
            }
            return;
        }
        for (int i = 1; i <= num.size(); ++i) {
            string curr_str = num.substr(0, i);
            long curr_num = stol(curr_str);
            if (curr_num> INT_MAX || curr_num < INT_MIN) return; 
            if (i > 1 && num[0] == '0') return; 
            if (i == 1) {
                dfs(num.substr(1), target, curr_num, curr_num, curr_num, expression + "+" + curr_str, return_value, ans);
            } else {
                dfs(num.substr(1), target, current + curr_num, curr_num, curr_num * previous, expression + "+" + curr_str, return_value, ans);
                dfs(num.substr(1), target, current - curr_num, -curr_num, curr_num * previous, expression + "-" + curr_str, return_value, ans);
                dfs(i > 1 ? num.substr(1) : num, target, current - previous + curr_num * intermediate, curr_num * previous - intermediate, curr_num * intermediate, expression + "*" + curr_str, return_value, ans);
            }
        }
    }
};