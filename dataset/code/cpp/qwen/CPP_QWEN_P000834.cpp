#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool canPaint(const vector<int>& boards, int painters, int maxTime) {
    int paintersUsed = 1;
    long long currentLength = 0;
    for (int b : boards) {
        if (currentLength + b > maxTime) {
            paintersUsed++;
            currentLength = b;
            if (paintersUsed > painters) return false;
        } else {
            currentLength += b;
        }
    }
    return true;
}

int main() {
    int n, painters;
    cin >> n >> painters;
    vector<int> boards(n);
    for (int i = 0; i < n; ++i) cin >> boards[i];
    
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0LL);
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canPaint(boards, painters, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
