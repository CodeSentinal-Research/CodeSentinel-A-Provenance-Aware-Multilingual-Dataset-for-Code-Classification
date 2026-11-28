#include <iostream>
using namespace std;
class Solution {
public:
    pair<int,int> swap(int a, int b) {
        return {b, a};
    }
};
int main() {
    int a, b; cin >> a >> b;
    auto [x, y] = Solution().swap(a, b);
    cout << x << " " << y << "\n";
}
