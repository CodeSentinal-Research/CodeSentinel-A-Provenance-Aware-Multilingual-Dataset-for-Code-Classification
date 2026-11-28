import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] count = new int[26];
        int maxFreq = 0;
        for (char c : tasks) {
            count[c - 'A']++;
            maxFreq = Math.max(maxFreq, count[c - 'A']);
        }
        int maxCount = 0;
        for (int f : count) {
            if (f == maxFreq) maxCount++;
        }
        return Math.max(tasks.length, (maxFreq - 1) * (n + 1) + maxCount);
    }
}