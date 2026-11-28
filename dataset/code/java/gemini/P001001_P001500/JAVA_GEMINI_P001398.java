import java.util.*;

public class Solution {
    public List<String> commonChars(String[] words) {
        int[] common = new int[26];
        Arrays.fill(common, Integer.MAX_VALUE);

        for (String w : words) {
            int[] count = new int[26];
            for (char c : w.toCharArray()) count[c - 'a']++;
            for (int i = 0; i < 26; i++) common[i] = Math.min(common[i], count[i]);
        }

        List<String> res = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            while (common[i]-- > 0) {
                res.add(String.valueOf((char)('a' + i)));
            }
        }
        return res;
    }
}