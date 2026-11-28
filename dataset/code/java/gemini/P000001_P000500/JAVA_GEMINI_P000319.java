import java.util.*;

public class Solution {
    public static boolean isOneEditDistance(String s, String t) {
        if (s.equals(t)) return false;
        int m = s.length(), n = t.length();
        if (Math.abs(m - n) > 1) return false;
        for (int i = 0; i < Math.min(m, n); i++) {
            if (s.charAt(i) != t.charAt(i)) {
                if (m == n) return s.substring(i + 1).equals(t.substring(i + 1));
                else if (m < n) return s.substring(i).equals(t.substring(i + 1));
                else return s.substring(i + 1).equals(t.substring(i));
            }
        }
        return Math.abs(m - n) == 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String t = scanner.hasNext() ? scanner.next() : "";
            System.out.println(isOneEditDistance(s, t) ? "Yes" : "No");
        }
    }
}