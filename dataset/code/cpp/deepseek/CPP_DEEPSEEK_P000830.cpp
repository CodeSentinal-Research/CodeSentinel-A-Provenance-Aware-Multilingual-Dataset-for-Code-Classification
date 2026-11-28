#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& piles, int mid, int h) {
    int hours = 0;
    for(int i = 0; i < piles.size(); i++) {
        hours += piles[i] / mid;
        if(piles[i] % mid != 0) hours++;
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    while(low < high) {
        int mid = (low + high) / 2;
        if(isPossible(piles, mid, h)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for(int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    cout << minEatingSpeed(piles, h);
    return 0;
}