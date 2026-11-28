/*## Count Subarrays with Sum = K (Negatives Allowed)

## Problem
Count subarrays whose sum equals K. Elements may be positive or negative.

## Idea / Intuition
Maintain running prefix sum pref. A subarray ending at current index has sum K if there exists a previous prefix equal to pref - K. Track frequencies of prefix sums in a hashmap to count how many such prefixes have occurred.

## Algorithm
- Start with freq[0] = 1, pref = 0, ans = 0.
- For each element x:
    - pref += x.
    - ans += freq.get(pref - K).
    - Increment freq[pref].

## Correctness Sketch
Sum of subarray (l, r] is pref[r] - pref[l]. Setting this to K gives pref[l] = pref[r] - K. The hashmap counts how many l satisfy this relation; adding that count captures all valid subarrays ending at r. Each subarray is counted once when its right endpoint is processed.

## Complexity
- Time: O(n)
- Space: O(n) worst case for distinct prefix sums

## Notes
- Using long for pref avoids overflow when sums grow beyond int range.
*/
import java.util.*;

public class CountSubarraysSumEqualsK {
    public static long count(int[] arr, int K) {
        Map<Long, Integer> freq = new HashMap<>();
        freq.put(0L, 1);
        long pref = 0;
        long ans = 0;
        for (int x : arr) {
            pref += x;
            ans += freq.getOrDefault(pref - K, 0);
            freq.put(pref, freq.getOrDefault(pref, 0) + 1);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {1, -1, 2, 3, -2};
        System.out.println(count(arr, 3)); // 3
    }
}
