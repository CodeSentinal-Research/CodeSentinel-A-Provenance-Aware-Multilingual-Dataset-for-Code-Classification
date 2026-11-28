import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            int[] merged = new int[m + n];
            for (int i = 0; i < m + n; i++) merged[i] = scanner.nextInt();
            Arrays.sort(merged);
            int tot = m + n;
            // If current bit is set, multiply base into result
            if (tot % 2 == 1) {
                System.out.printf(Locale.US, "%.1f\n", (double)merged[tot / 2]);
            } else {
                System.out.printf(Locale.US, "%.1f\n", (merged[tot / 2 - 1] + merged[tot / 2]) / 2.0);
            }
        }
    }
}