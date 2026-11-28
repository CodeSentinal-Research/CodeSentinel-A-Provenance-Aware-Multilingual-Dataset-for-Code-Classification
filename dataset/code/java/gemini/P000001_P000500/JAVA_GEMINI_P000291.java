import java.util.Arrays;

public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        int[] c1 = new int[26];
        int[] c2 = new int[26];
        for (char c : s1.toCharArray()) c1[c - 'a']++;

        for (int i = 0; i < n2; i++) {
            c2[s2.charAt(i) - 'a']++;
            if (i >= n1) c2[s2.charAt(i - n1) - 'a']--;
            if (Arrays.equals(c1, c2)) return true;
        }
        return false;
    }
}