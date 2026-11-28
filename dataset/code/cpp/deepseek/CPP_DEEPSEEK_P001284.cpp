Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& top, vector<int>& bottom, int n, int A, int B) {
    int rotations_top = (n - (top[0] == B) - (top[n-1] == B)) / 2;
    int rotations_bottom = (n - (bottom[0] == A) - (bottom[n-1] == A)) / 2;
    if (rotations_top == -1 || rotations_bottom == -1) {
        return -1;
    }
    return min(rotations_top, rotations_bottom);
}

int main() {
    int n;
    cin >> n;
    vector<int> top(n), bottom(n);
    for (int i = 0; i < n; i++) {
        cin >> top[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> bottom[i];
    }
    int A = top[0], B = bottom[0];
    cout << solve(top, bottom, n, A, B) << endl;
    return 0;
}

This program reads the size of the arrays and the arrays themselves from the standard input. It then calls the `solve` function, which calculates and returns the minimum number of rotations needed to make both rows equal. If no rotation is possible, it returns -1.