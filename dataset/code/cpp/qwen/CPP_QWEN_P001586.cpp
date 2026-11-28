#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
};

int main() {
    int n;
    long long carpetLen;
    cin >> n >> carpetLen;
    
    vector<Interval> tiles(n);
    for (int i = 0; i < n; ++i) {
        cin >> tiles[i].start >> tiles[i].end;
    }
    
    sort(tiles.begin(), tiles.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });
    
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i+1] = prefixSum[i] + (tiles[i].end - tiles[i].start + 1);
    }
    
    long long maxCovered = 0;
    
    for (int i = 0; i < n; ++i) {
        long long carpetEnd = tiles[i].start + carpetLen - 1;
        
        int lo = i, hi = n - 1, bestJ = i - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (tiles[mid].start <= carpetEnd) {
                bestJ = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        long long covered = prefixSum[bestJ + 1] - prefixSum[i];
        
        if (bestJ >= i && tiles[bestJ].end > carpetEnd) {
            covered -= (tiles[bestJ].end - carpetEnd);
        }
        
        maxCovered = max(maxCovered, covered);
    }
    
    cout << maxCovered << endl;
    return 0;
}
