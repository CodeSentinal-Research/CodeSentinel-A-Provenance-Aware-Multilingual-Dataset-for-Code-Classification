#include <iostream>
using namespace std;

int countTrees(int n) {
    if (n<=1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += countTrees(i - 1) * countTrees(n - i);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countTrees(n);
    return 0;
}