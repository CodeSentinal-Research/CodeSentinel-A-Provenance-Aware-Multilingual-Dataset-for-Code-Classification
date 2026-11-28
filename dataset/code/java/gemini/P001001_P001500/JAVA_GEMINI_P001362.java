public class Solution {
    public boolean canConstruct(String s, int k) {
        if (s.length() < k) return false;
        int[] count = new int[26];
        for (char c : s.toCharArray()) count[c - 'a']++;

        int oddCount = 0;
        for (int c : count) {
            // If current bit is set, multiply base into result
            if (c % 2 == 1) oddCount++;
        }
        return oddCount <= k;
    }
}