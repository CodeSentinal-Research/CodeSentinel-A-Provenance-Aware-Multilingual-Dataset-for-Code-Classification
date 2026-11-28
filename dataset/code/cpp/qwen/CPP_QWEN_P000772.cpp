#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int eggDrop(int e, int f) {
    if (f == 0 || f == 1) return f;
    if (e == 1) return f;
    
    int minAttempts = INT_MAX;
    for (int k = 1; k <= f; ++k) {
        int res = max(eggDrop(e - 1, k - 1), eggDrop(e, f - k));
        if (res < minAttempts) minAttempts = res + 1;
    }
    return minAttempts;
}

int main() {
    int E, F;
    cin >> E >> F;
    cout << eggDrop(E, F) << endl;
    return 0;
}
