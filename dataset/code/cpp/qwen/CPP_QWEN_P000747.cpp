#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int N;
    cin >> N;
    cout << climbStairs(N) << endl;
    return 0;
}
