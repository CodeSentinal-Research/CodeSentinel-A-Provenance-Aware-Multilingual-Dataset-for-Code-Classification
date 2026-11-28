#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long paintBoards(int n, vector<int> &boards, int painters) {
    long long start = *min_element(boards.begin(), boards.end());
    long long end = accumulate(boards.begin(), boards.end(), 0LL);
    long long totalPainters = (long long)boards.size() * painters;

    while (start < end) {
        long long mid = (start + end) / 2;
        long long requiredPainters = (mid + totalPainters) / (boards.size() * painters);
        long long remainingBlocks = (mid + totalPainters) % (boards.size() * painters);
        long long paintersUsed = requiredPainters + (remainingBlocks > painters ? 1 : 0);

        if (paintersUsed <= painters) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    int n;
    cin >> n;

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    int painters;
    cin >> painters;

    cout << paintBoards(n, boards, painters) << endl;
    return 0;
}