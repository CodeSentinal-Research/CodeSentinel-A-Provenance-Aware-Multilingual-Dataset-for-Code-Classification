import java.util.*;

public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if (s.length() < p.length()) return res;

        int[] pCount = new int[26];
        int[] sCount = new int[26];
        for (char c : p.toCharArray()) pCount[c - 'a']++;

        int pLen = p.length();
        for (int i = 0; i < s.length(); i++) {
            sCount[s.charAt(i) - 'a']++;
            if (i >= pLen) {
                sCount[s.charAt(i - pLen) - 'a']--;
            }
            if (Arrays.equals(sCount, pCount)) {
                res.add(i - pLen + 1);
            }
        }
        return res;
    }
}