import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next(), p = sc.next();
            if (s.length() < p.length()) {
                System.out.println(0);
                return;
            }
            int[] pCount = new int[26], sCount = new int[26];
            for (char c : p.toCharArray()) pCount[c - 'a']++;

            int pLen = p.length();
            int ans = 0;

            for (int i = 0; i < s.length(); i++) {
                sCount[s.charAt(i) - 'a']++;
                if (i >= pLen) sCount[s.charAt(i - pLen) - 'a']--;
                if (Arrays.equals(pCount, sCount)) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}