/*
Sliding Window Pattern
Mathematical Foundation: For subarray A[i..j], maintain window invariant:
- Fixed size: |window| = k, slide by 1
- Variable size: expand while valid, contract when invalid
- Use hashmap/deque for O(1) operations
Time: O(n), Space: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

// Maximum Sum Subarray of Size K (Fixed Window)
// LeetCode: 643. Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
// Related:
// 1456. Maximum Number of Vowels in a Substring of Given Length
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// 1052. Grumpy Bookstore Owner
// https://leetcode.com/problems/grumpy-bookstore-owner/
// 2090. K Radius Subarray Averages
// https://leetcode.com/problems/k-radius-subarray-averages/
// 1100. Find K-Length Substrings With No Repeated Characters
// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
int maxSumSubarray(vector<int>& a, int k) {
    int s = 0, mx = INT_MIN;
    for (int i = 0; i < a.size(); i++) {
        s += a[i];
        if (i >= k - 1) {
            mx = max(mx, s);
            s -= a[i - k + 1];
        }
    }
    return mx;
}

// Longest Substring Without Repeating Characters (Variable Window)
// LeetCode: 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Related:
// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/
// 992. Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/
// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int l = 0, mx = 0;
    for (int r = 0; r < s.size(); r++) {
        while (st.count(s[r])) st.erase(s[l++]);
        st.insert(s[r]);
        mx = max(mx, r - l + 1);
    }
    return mx;
}

// Minimum Window Substring (Shrinking Window)
// LeetCode: 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/
// Related:
// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/
// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// 30. Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// 727. Minimum Window Subsequence
// https://leetcode.com/problems/minimum-window-subsequence/
// 632. Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
string minWindow(string s, string t) {
    unordered_map<char, int> need, have;
    for (char c : t) need[c]++;
    int l = 0, formed = 0, mn = INT_MAX, start = 0;
    for (int r = 0; r < s.size(); r++) {
        char c = s[r];
        have[c]++;
        if (need.count(c) && have[c] == need[c]) formed++;
        while (formed == need.size()) {
            if (r - l + 1 < mn) {
                mn = r - l + 1;
                start = l;
            }
            char lc = s[l];
            have[lc]--;
            if (need.count(lc) && have[lc] < need[lc]) formed--;
            l++;
        }
    }
    return mn == INT_MAX ? "" : s.substr(start, mn);
}

// Longest Substring with At Most K Distinct Characters (Variable Window)
// LeetCode: 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Related:
// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/
// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// 2024. Maximize the Confusion of an Exam
// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
// 1493. Longest Subarray of 1's After Deleting One Element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> mp;
    int l = 0, mx = 0;
    for (int r = 0; r < s.size(); r++) {
        mp[s[r]]++;
        while (mp.size() > k) {
            if (--mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
        mx = max(mx, r - l + 1);
    }
    return mx;
}

// Sliding Window Maximum (Deque-based)
// LeetCode: 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/
// Related:
// 155. Min Stack
// https://leetcode.com/problems/min-stack/
// 862. Shortest Subarray with Sum at Least K
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// 1696. Jump Game VI
// https://leetcode.com/problems/jump-game-vi/
// 1425. Constrained Subsequence Sum
// https://leetcode.com/problems/constrained-subsequence-sum/
// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// 918. Maximum Sum Circular Subarray
// https://leetcode.com/problems/maximum-sum-circular-subarray/
vector<int> maxSlidingWindow(vector<int>& a, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(a[dq.front()]);
    }
    return res;
}

// Subarray Sum Equals K (Hash Map + Prefix Sum)
// LeetCode: 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
// Related:
// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// 325. Maximum Size Subarray Sum Equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
// 930. Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/
// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/
// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
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
