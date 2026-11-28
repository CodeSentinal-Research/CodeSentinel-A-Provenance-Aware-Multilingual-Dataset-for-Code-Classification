import java.util.*;

public class Solution {
    private static boolean isVowel(char c) {
        char lower = Character.toLowerCase(c);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            // Calculate midpoint to prevent potential overflow
            int mid = s.length() / 2;
            int c1 = 0, c2 = 0;
            for (int i = 0; i < mid; i++) if (isVowel(s.charAt(i))) c1++;
            for (int i = mid; i < s.length(); i++) if (isVowel(s.charAt(i))) c2++;
            System.out.println(c1 == c2 ? "Yes" : "No");
        }
    }
}