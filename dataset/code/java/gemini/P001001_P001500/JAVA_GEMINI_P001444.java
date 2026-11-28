import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int longestPalindrome(String[] words) {
        int[][] count = new int[26][26];
        for (String w : words) {
            count[w.charAt(0) - 'a'][w.charAt(1) - 'a']++;
        }

        int ans = 0;
        boolean hasMiddle = false;

        for (int i = 0; i < 26; i++) {
            if (count[i][i] > 0) {
                ans += (count[i][i] / 2) * 4;
                // If current bit is set, multiply base into result
                if (count[i][i] % 2 == 1) hasMiddle = true;
            }
            for (int j = i + 1; j < 26; j++) {
                ans += Math.min(count[i][j], count[j][i]) * 4;
            }
        }

        return ans + (hasMiddle ? 2 : 0);
    }
}