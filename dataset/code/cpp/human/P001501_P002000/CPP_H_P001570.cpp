/*
Prefix Sum Pattern
Mathematical Foundation: prefix[i] = sum(A[0..i])
Range sum query: sum(A[l..r]) = prefix[r] - prefix[l-1]
2D: prefix[i][j] = sum of rectangle (0,0) to (i,j)
Time: O(n) preprocess, O(1) query
*/

#include <bits/stdc++.h>
using namespace std;

// 1D Prefix Sum
// LeetCode: 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/
// Related:
// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
// 1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/
// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
// 1991. Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array/
class PrefixSum {
public:
    vector<long long> p;
    
    PrefixSum(vector<int>& a) {
        p.resize(a.size() + 1);
        for (int i = 0; i < a.size(); i++)
            p[i + 1] = p[i] + a[i];
    }
    
    long long query(int l, int r) {
        return p[r + 1] - p[l];
    }
};

// 2D Prefix Sum
// LeetCode: 304. Range Sum Query 2D - Immutable
// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Related:
// 308. Range Sum Query 2D - Mutable
// https://leetcode.com/problems/range-sum-query-2d-mutable/
// 1277. Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// 1314. Matrix Block Sum
// https://leetcode.com/problems/matrix-block-sum/
// 1738. Find Kth Largest XOR Coordinate Value
// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// 1878. Get Biggest Three Rhombus Sums in a Grid
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
class PrefixSum2D {
public:
    vector<vector<long long>> p;
    
    PrefixSum2D(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        p.assign(m + 1, vector<long long>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = a[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    }
    
    long long query(int r1, int c1, int r2, int c2) {
        return p[r2+1][c2+1] - p[r1][c2+1] - p[r2+1][c1] + p[r1][c1];
    }
};

// Subarray Sum Equals K
// LeetCode: 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
// Related:
// 930. Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/
// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// 1074. Number of Submatrices That Sum to Target
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// 325. Maximum Size Subarray Sum Equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/
int subarraySum(vector<int>& a, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int s = 0, cnt = 0;
    for (int x : a) {
        s += x;
        cnt += mp[s - k];
        mp[s]++;
    }
    return cnt;
}

// Contiguous Array (equal 0s and 1s)
// LeetCode: 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/
// Related:
// 1371. Find the Longest Substring Containing Vowels in Even Counts
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// 1542. Find Longest Awesome Substring
// https://leetcode.com/problems/find-longest-awesome-substring/
// 1915. Number of Wonderful Substrings
// https://leetcode.com/problems/number-of-wonderful-substrings/
// 1124. Longest Well-Performing Interval
// https://leetcode.com/problems/longest-well-performing-interval/
int findMaxLength(vector<int>& a) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int s = 0, mx = 0;
    for (int i = 0; i < a.size(); i++) {
        s += a[i] ? 1 : -1;
        if (mp.count(s)) mx = max(mx, i - mp[s]);
        else mp[s] = i;
    }
    return mx;
}

// Product of Array Except Self (Prefix/Suffix Product)
// LeetCode: 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// Related:
// 1352. Product of the Last K Numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers/
// 1339. Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// 1769. Minimum Number of Operations to Move All Balls to Each Box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
// 2906. Construct Product Matrix
// https://leetcode.com/problems/construct-product-matrix/
vector<int> productExceptSelf(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, 1);
    for (int i = 1; i < n; i++)
        res[i] = res[i-1] * a[i-1];
    int r = 1;
    for (int i = n-1; i >= 0; i--) {
        res[i] *= r;
        r *= a[i];
    }
    return res;
}

// Range Sum Query - Immutable (Alternative Implementation)
// LeetCode: 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/
// Related:
// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/
// 1588. Sum of All Odd Length Subarrays
// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// 2574. Left and Right Sum Differences
// https://leetcode.com/problems/left-and-right-sum-differences/
// 2485. Find the Pivot Integer
// https://leetcode.com/problems/find-the-pivot-integer/
// 1413. Minimum Value to Get Positive Step by Step Sum
// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
class NumArray {
public:
    vector<int> p;
    NumArray(vector<int>& a) : p(a.size() + 1) {
        for (int i = 0; i < a.size(); i++)
            p[i + 1] = p[i] + a[i];
    }
    int sumRange(int l, int r) {
        return p[r + 1] - p[l];
    }
};
