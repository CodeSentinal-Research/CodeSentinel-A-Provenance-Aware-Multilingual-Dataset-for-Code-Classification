#include <iostream>
using namespace std;
class Solution {
public:
    long long factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n-1);
    }
};
int main() {
    int n; cin >> n;
    cout << Solution().factorial(n) << "\n";
}
