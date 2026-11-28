import java.util.*;

public class Solution {
    private static Set<String> pals = new HashSet<>();

    // Calculates modular exponentiation (base^exp % mod) efficiently.
    private static void expand(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            pals.add(s.substring(l, r + 1));
            l--;
            r++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            for (int i = 0; i < s.length(); i++) {
                expand(s, i, i);
                expand(s, i, i + 1);
            }
            System.out.println(pals.size());
        }
        sc.close();
    }
}