import java.util.*;

public class Solution {
    public static boolean checkAlmostEquivalent(String word1, String word2) {
        int[] count = new int[26];
        for (char c : word1.toCharArray()) count[c - 'a']++;
        for (char c : word2.toCharArray()) count[c - 'a']--;
        for (int i = 0; i < 26; i++) {
            if (Math.abs(count[i]) > 3) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String w1 = scanner.next();
            String w2 = scanner.next();
            System.out.println(checkAlmostEquivalent(w1, w2) ? "Yes" : "No");
        }
    }
}