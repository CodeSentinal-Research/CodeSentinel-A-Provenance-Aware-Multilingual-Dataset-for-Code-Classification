import java.util.*;

public class Solution {
    public static boolean wordPattern(String pattern, String s) {
        String[] words = s.trim().split("\\s+");
        if (pattern.length() != words.length) return false;
        Map<Character, String> pw = new HashMap<>();
        Map<String, Character> wp = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern.charAt(i);
            String w = words[i];
            if (pw.containsKey(p) && !pw.get(p).equals(w)) return false;
            if (wp.containsKey(w) && wp.get(w) != p) return false;
            pw.put(p, w);
            wp.put(w, p);
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String pattern = scanner.next();
            String s = scanner.nextLine().trim();
            if (s.isEmpty() && scanner.hasNextLine()) {
                s = scanner.nextLine().trim();
            }
            System.out.println(wordPattern(pattern, s) ? "Yes" : "No");
        }
    }
}