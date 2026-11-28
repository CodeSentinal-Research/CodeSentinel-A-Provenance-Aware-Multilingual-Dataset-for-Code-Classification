#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<std::string> strStack;
        std::stack<int> numStack;
        std::string curStr = "";
        int curNum = 0;

        for (char c : s) {
            if (std::isdigit(c)) {
                curNum = curNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(curNum);
                strStack.push(curStr);
                curStr = "";
                curNum = 0;
            } else if (c == ']') {
                int k = numStack.top(); numStack.pop();
                std::string prevStr = strStack.top(); strStack.pop();
                std::string repeated = "";
                for (int i = 0; i < k; i++) repeated += curStr;
                curStr = prevStr + repeated;
            } else {
                curStr += c;
            }
        }
        return curStr;
    }
};