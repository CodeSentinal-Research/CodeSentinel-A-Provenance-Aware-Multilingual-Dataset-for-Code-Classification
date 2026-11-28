import java.util.*;

public class Solution {
    public static boolean canConstruct(String ransomNote, String magazine) {
        int[] counts = new int[26];
        for (char c : magazine.toCharArray()) counts[c - 'a']++;
        for (char c : ransomNote.toCharArray()) {
            if (--counts[c - 'a'] < 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String r = scanner.next();
            String m = scanner.next();
            System.out.println(canConstruct(r, m) ? "Yes" : "No");
        }
    }
}