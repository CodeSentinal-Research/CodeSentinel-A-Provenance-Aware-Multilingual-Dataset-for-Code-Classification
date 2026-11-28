#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canEat(const vector<int>& piles, int h, int speed) {
    long long hours = 0;
    for (int p : piles) {
        hours += (p + speed - 1) / speed;
    }
    return hours <= h;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) cin >> piles[i];
    
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canEat(piles, h, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
