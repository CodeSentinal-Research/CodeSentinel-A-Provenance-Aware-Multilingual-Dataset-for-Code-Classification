#include <iostream>
using namespace std;
class Solution {
public:
    long long fib(int n) {
        if (n <= 1) return n;
        long long a = 0, b = 1;
        for (int i = 2; i <= n; i++) { long long c = a+b; a=b; b=c; }
        return b;
    }
};
int main() {
    int n; cin >> n;
    cout << Solution().fib(n) << "\n";
}
