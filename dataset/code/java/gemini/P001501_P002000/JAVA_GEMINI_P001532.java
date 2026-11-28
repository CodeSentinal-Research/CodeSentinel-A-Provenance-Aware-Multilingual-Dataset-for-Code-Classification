import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            int k = sc.nextInt();
            if (k == 0) {
                System.out.println(0);
                return;
            }
            Map<Character, Integer> count = new HashMap<>();
            int l = 0, maxLen = 0;

            for (int r = 0; r < s.length(); r++) {
                char c = s.charAt(r);
                count.put(c, count.getOrDefault(c, 0) + 1);
                while (count.size() > k) {
                    char left = s.charAt(l);
                    count.put(left, count.get(left) - 1);
                    if (count.get(left) == 0) count.remove(left);
                    l++;
                }
                maxLen = Math.max(maxLen, r - l + 1);
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}