import java.util.*;

public class Solution {
    public int minDeletions(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) count[c - 'a']++;

        Set<Integer> used = new HashSet<>();
        int deletions = 0;

        for (int freq : count) {
            while (freq > 0 && used.contains(freq)) {
                freq--;
                deletions++;
            }
            used.add(freq);
        }
        return deletions;
    }
}