import java.util.*;

public class Solution {
    public static boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Character> st = new HashMap<>();
        Map<Character, Character> ts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i), c2 = t.charAt(i);
            if (st.containsKey(c1) && st.get(c1) != c2) return false;
            if (ts.containsKey(c2) && ts.get(c2) != c1) return false;
            st.put(c1, c2);
            ts.put(c2, c1);
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String t = scanner.next();
            System.out.println(isIsomorphic(s, t) ? "Yes" : "No");
        }
    }
}