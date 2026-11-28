#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, long long> memo;

long long countTrue(string expr, int i, int j, bool isTrue) {
    string key = to_string(i) + "," + to_string(j) + "," + to_string(isTrue);
    if (memo.find(key) != memo.end()) return memo[key];
    
    if (i == j) {
        if (isTrue) return expr[i] == 'T' ? 1 : 0;
        else return expr[i] == 'F' ? 1 : 0;
    }
    
    long long ways = 0;
    for (int k = i + 1; k < j; k += 2) {
        char op = expr[k];
        long long lT = countTrue(expr, i, k - 1, true);
        long long lF = countTrue(expr, i, k - 1, false);
        long long rT = countTrue(expr, k + 1, j, true);
        long long rF = countTrue(expr, k + 1, j, false);
        
        long long total = (lT + lF) * (rT + rF);
        long long trueWays = 0;
        
        if (op == '&') trueWays = lT * rT;
        else if (op == '|') trueWays = lT * rT + lT * rF + lF * rT;
        else if (op == '^') trueWays = lT * rF + lF * rT;
        
        if (isTrue) ways += trueWays;
        else ways += total - trueWays;
    }
    
    memo[key] = ways;
    return ways;
}

int main() {
    string expr;
    cin >> expr;
    cout << countTrue(expr, 0, expr.length() - 1, true) << endl;
    return 0;
}
