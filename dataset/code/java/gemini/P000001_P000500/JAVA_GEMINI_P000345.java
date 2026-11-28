import java.util.*;

public class Solution {
    public static boolean sameCharacters(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int[] count = new int[256];
        for (char c : s1.toCharArray()) count[c]++;
        for (char c : s2.toCharArray()) {
            if (--count[c] < 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s1 = scanner.next();
            String s2 = scanner.next();
            System.out.println(sameCharacters(s1, s2) ? "Yes" : "No");
        }
    }
}