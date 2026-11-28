import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] pref = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int x = scanner.nextInt();
                pref[i + 1] = pref[i] + (x % 2 == 0 ? 1 : 0);
            }
            int q = scanner.nextInt();
            while (q-- > 0) {
                int l = scanner.nextInt(), r = scanner.nextInt();
                System.out.println(pref[r + 1] - pref[l]);
            }
        }
    }
}