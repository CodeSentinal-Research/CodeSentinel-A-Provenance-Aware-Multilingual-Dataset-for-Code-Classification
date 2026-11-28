#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> memo;

bool canIWin(int maxChoosable, int desiredTotal, int usedMask) {
    if (memo.find(usedMask) != memo.end()) return memo[usedMask];
    
    for (int i = 1; i <= maxChoosable; ++i) {
        if (!(usedMask & (1 << i))) {
            if (i >= desiredTotal || !canIWin(maxChoosable, desiredTotal - i, usedMask | (1 << i))) {
                memo[usedMask] = true;
                return true;
            }
        }
    }
    
    memo[usedMask] = false;
    return false;
}

int main() {
    int maxChoosable, desiredTotal;
    cin >> maxChoosable >> desiredTotal;
    
    if (maxChoosable * (maxChoosable + 1) / 2 < desiredTotal) {
        cout << "false" << endl;
        return 0;
    }
    
    cout << (canIWin(maxChoosable, desiredTotal, 0) ? "true" : "false") << endl;
    return 0;
}
