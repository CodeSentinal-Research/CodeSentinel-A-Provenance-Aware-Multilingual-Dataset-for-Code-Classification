#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<tuple<int, int, bool>, long long> memo;

long long solve(const string& s, int i, int j, bool isTrue) {
    if (i == j) {
        if (isTrue) return s[i] == 'T' ? 1 : 0;
        else return s[i] == 'F' ? 1 : 0;
    }
    
    auto key = make_tuple(i, j, isTrue);
    if (memo.find(key) != memo.end()) return memo[key];
    
    long long ways = 0;
    for (int k = i + 1; k < j; k += 2) {
        char op = s[k];
        long long lT = solve(s, i, k - 1, true);
        long long lF = solve(s, i, k - 1, false);
        long long rT = solve(s, k + 1, j, true);
        long long rF = solve(s, k + 1, j, false);
        
        long long total = (lT + lF) * (rT + rF);
        long long trueWays = 0;
        
        if (op == '&') trueWays = lT * rT;
        else if (op == '|') trueWays = lT * rT + lT * rF + lF * rT;
        else if (op == '^') trueWays = lT * rF + lF * rT;
        
        if (isTrue) ways += trueWays;
        else ways += total - trueWays;
    }
    
    return memo[key] = ways;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1, true) << endl;
    return 0;
}
