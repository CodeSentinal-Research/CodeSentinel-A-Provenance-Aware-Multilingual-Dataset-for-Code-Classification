import java.util.*;

public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int ns = s.length(), np = p.length();
        if (ns < np) return res;

        int[] pCount = new int[26];
        int[] sCount = new int[26];
        for (char c : p.toCharArray()) pCount[c - 'a']++;

        for (int i = 0; i < ns; i++) {
            sCount[s.charAt(i) - 'a']++;
            if (i >= np) sCount[s.charAt(i - np) - 'a']--;
            if (Arrays.equals(pCount, sCount)) {
                res.add(i - np + 1);
            }
        }
        return res;
    }
}