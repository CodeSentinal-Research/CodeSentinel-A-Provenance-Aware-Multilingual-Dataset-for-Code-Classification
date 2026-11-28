#include <string>
#include <unordered_map>

class Solution {
    std::unordered_map<std::string, bool> memo;
public:
    bool canWin(std::string currentState) {
        if (memo.count(currentState)) return memo[currentState];
        for (int i = 0; i < (int)currentState.length() - 1; i++) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                std::string nextState = currentState.substr(0, i) + "--" + currentState.substr(i + 2);
                if (!canWin(nextState)) {
                    return memo[currentState] = true;
                }
            }
        }
        return memo[currentState] = false;
    }
};