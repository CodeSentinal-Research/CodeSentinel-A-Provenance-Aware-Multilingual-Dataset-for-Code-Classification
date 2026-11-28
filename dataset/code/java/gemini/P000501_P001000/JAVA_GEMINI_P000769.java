import java.util.*;
public class Solution {
    static Map<String, Boolean> memo = new HashMap<>();
    static boolean isScramble(String s1, String s2) {
        if (s1.equals(s2)) return true;
        String key = s1 + "#" + s2;
        if (memo.containsKey(key)) return memo.get(key);
        char[] t1 = s1.toCharArray(), t2 = s2.toCharArray();
        Arrays.sort(t1); Arrays.sort(t2);
        if (!Arrays.equals(t1, t2)) { memo.put(key, false); return false; }
        int n = s1.length();
        for (int i = 1; i < n; i++) {
            if ((isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i))) ||
                (isScramble(s1.substring(0, i), s2.substring(n - i)) && isScramble(s1.substring(i), s2.substring(0, n - i)))) {
                memo.put(key, true);
                return true;
            }
        }
        memo.put(key, false);
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            System.out.println(isScramble(scanner.next(), scanner.next()) ? "true" : "false");
        }
    }
}