Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> jumps(N);
    for(int i = 0; i < N; i++) {
        cin >> jumps[i];
    }

    int reachable = 1;
    int maxReach = 0;
    for(int i = 0; i < N; i++) {
        if(i > maxReach) {
            reachable = 0;
            break;
        }
        maxReach = max(maxReach, i + jumps[i]);
    }

    if(reachable) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

In this code, we first read the number of elements N. Then we read N integers representing the maximum jump length. We initialize reachable to 1 and maxReach to 0. We iterate over the array. If at any point we're past the maximum reachable point (i.e., `i > maxReach`), we can't reach the last index, so we set reachable to 0 and break the loop. Otherwise, we update maxReach to the maximum of `maxReach` and `i + jumps[i]` (the maximum reachable point from the current index). Finally, we print the result.