#include <iostream>
using namespace std;
class Solution {
public:
    string evenOdd(int n) { return n % 2 == 0 ? "Even" : "Odd"; }
};
int main() {
    int n; cin >> n;
    cout << Solution().evenOdd(n) << "\n";
}
