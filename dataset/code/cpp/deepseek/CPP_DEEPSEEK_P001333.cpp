#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string s, int target) {
        vector<string> res;
        dfs(s, target, 0, 0, "", 0, 0);
        return res;
    }

private:
    void dfs(string s, int target, long curr, long prev, string expression, int start, bool isPrevDigit) {
        if (start == s.size() && curr == target) {
            res.push_back(expression);
            return;
        }

        long next = 0;
        for (int end = start; end < s.size(); end++) {
            next = next * 10 + (s[end] - '0');
            if (s[start] == '0' && end != start) continue;

            if (start == 0) {
                dfs(s, target, next, next, expression + "+" + to_string(next), end + 1, true);
            } else {
                if (isPrevDigit) {
                    dfs(s, target, curr - prev + next, prev, expression + "+" + to_string(next), end + 1, true);
                } else {
                    dfs(s, target, curr + next, next, expression + "+" + to_string(next), end + 1, true);
                }

                dfs(s, target, curr - prev + next * next, prev * next, expression + "*" + to_string(next), end + 1, false);
            }
        }
    }
};

int main() {
    Solution sol;
    string s;
    int target;
    cin >> s >> target;
    vector<string> result = sol.addOperators(s, target);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}