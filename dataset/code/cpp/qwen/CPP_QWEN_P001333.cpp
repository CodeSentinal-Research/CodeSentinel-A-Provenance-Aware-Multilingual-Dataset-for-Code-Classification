#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addOperatorsHelper(string num, int target, int start, long long currentVal, long long lastOperand, string expr, vector<string>& result) {
    if (start == num.length()) {
        if (currentVal == target) {
            result.push_back(expr);
        }
        return;
    }
    
    for (int end = start; end < num.length(); ++end) {
        string partStr = num.substr(start, end - start + 1);
        if (partStr.length() > 1 && partStr[0] == '0') break;
        
        long long partVal = stoll(partStr);
        
        if (start == 0) {
            addOperatorsHelper(num, target, end + 1, partVal, partVal, partStr, result);
        } else {
            addOperatorsHelper(num, target, end + 1, currentVal + partVal, partVal, expr + "+" + partStr, result);
            addOperatorsHelper(num, target, end + 1, currentVal - partVal, -partVal, expr + "-" + partStr, result);
            addOperatorsHelper(num, target, end + 1, currentVal - lastOperand + lastOperand * partVal, lastOperand * partVal, expr + "*" + partStr, result);
        }
    }
}

int main() {
    string num;
    int target;
    cin >> num >> target;
    vector<string> result;
    addOperatorsHelper(num, target, 0, 0, 0, "", result);
    
    for (const string& expr : result) {
        cout << expr << endl;
    }
    return 0;
}
