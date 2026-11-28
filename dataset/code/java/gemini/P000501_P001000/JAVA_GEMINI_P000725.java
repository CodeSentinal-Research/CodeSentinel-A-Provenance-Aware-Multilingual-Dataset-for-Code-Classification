import java.util.*;
public class Solution {
    static boolean backtrack(String s, int idx, long prev) {
        if (idx == s.length()) return true;
        long cur = 0;
        for (int i = idx; i < s.length(); i++) {
            cur = cur * 10 + (s.charAt(i) - '0');
            if (prev != 0 && cur == prev - 1) {
                if (backtrack(s, i + 1, cur)) return true;
            } else if (prev != 0 && cur >= prev) {
                break;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            boolean ok = false;
            long first = 0;
            for (int i = 0; i < s.length() - 1; i++) {
                first = first * 10 + (s.charAt(i) - '0');
                if (backtrack(s, i + 1, first)) { ok = true; break; }
            }
            System.out.println(ok ? "true" : "false");
        }
    }
}