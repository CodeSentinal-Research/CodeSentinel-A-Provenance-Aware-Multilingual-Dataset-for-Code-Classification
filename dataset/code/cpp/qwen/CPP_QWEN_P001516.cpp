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
    
    long long maxCovered = 0;
    long long currentCovered = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        currentCovered += (tiles[right].end - tiles[right].start + 1);
        
        // Shrink window if carpet doesn't cover from tiles[left].start to tiles[right].end
        while (tiles[right].end - tiles[left].start + 1 > carpetLen) {
            // Remove tiles[left] fully or partially?
            // The carpet starts at some position P.
            // This sliding window approach is tricky because carpet can slide.
            
            // Better approach: For each tile interval as the "leftmost" covered, calculate max coverage.
            // Or use two pointers on intervals.
            
            currentCovered -= (tiles[left].end - tiles[left].start + 1);
            left++;
        }
        
        // Calculate actual covered length considering carpet limit
        long long span = tiles[right].end - tiles[left].start + 1;
        long long covered = currentCovered;
        if (span > carpetLen) {
             // This case should be handled by while loop, but due to gaps, span might be large while covered is small.
             // Actually, if span > carpetLen, we might not cover all tiles in window.
             // But we want max covered.
             
             // Correct logic:
             // The carpet covers [P, P+carpetLen-1].
             // We want to maximize intersection with union of tiles.
        }
        
        maxCovered = max(maxCovered, covered);
    }
    
    // Re-evaluating standard solution for this problem type:
    // Sort intervals. Use prefix sums of lengths.
    // For each interval i, find furthest interval j such that tiles[j].end - tiles[i].start < carpetLen.
    // Covered = Sum(lengths i..j) - overlap adjustments? No, intervals are disjoint in typical problem statements or merged.
    // Assuming disjoint/non-overlapping sorted intervals for simplicity as per typical LeetCode 2271.
    
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i+1] = prefixSum[i] + (tiles[i].end - tiles[i].start + 1);
    }
    
    maxCovered = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // Find largest j such that tiles[j].end - tiles[i].start + 1 <= carpetLen ? 
        // No, carpet can start anywhere.
        // Optimal carpet placement starts at tiles[i].start.
        // Ends at tiles[i].start + carpetLen - 1.
        // Find how many tiles are fully or partially covered.
        
        long long carpetEnd = tiles[i].start + carpetLen - 1;
        
        // Binary search for last interval with start <= carpetEnd
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
        
        // Subtract part of last interval if it extends beyond carpetEnd
        if (bestJ >= i && tiles[bestJ].end > carpetEnd) {
            covered -= (tiles[bestJ].end - carpetEnd);
        }
        
        maxCovered = max(maxCovered, covered);
    }
    
    cout << maxCovered << endl;
    return 0;
}
