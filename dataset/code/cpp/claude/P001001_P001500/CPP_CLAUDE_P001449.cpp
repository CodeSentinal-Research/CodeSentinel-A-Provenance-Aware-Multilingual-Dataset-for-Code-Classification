#include <iostream>
using namespace std;
class Solution {
public:
    string classify(int n) {
        if (n > 0) return "Positive";
        if (n < 0) return "Negative";
        return "Zero";
    }
};
int main() {
    int n; cin >> n;
    cout << Solution().classify(n) << "\n";
}
