import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            char c = scanner.next().charAt(0);
            int n = s.length();
            int[] res = new int[n];
            int prev = -100000;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == c) prev = i;
                res[i] = i - prev;
            }
            prev = 100000;
            for (int i = n - 1; i >= 0; i--) {
                if (s.charAt(i) == c) prev = i;
                res[i] = Math.min(res[i], prev - i);
            }
            for (int i = 0; i < n; i++) {
                System.out.print(res[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
    }
}