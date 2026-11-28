import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] h = new long[n];
            for (int i = 0; i < n; i++) h[i] = scanner.nextLong();
            long maxSum = 0;
            for (int peak = 0; peak < n; peak++) {
                long currSum = h[peak], cur = h[peak];
                for (int i = peak - 1; i >= 0; i--) {
                    cur = Math.min(cur, h[i]);
                    currSum += cur;
                }
                cur = h[peak];
                for (int i = peak + 1; i < n; i++) {
                    cur = Math.min(cur, h[i]);
                    currSum += cur;
                }
                maxSum = Math.max(maxSum, currSum);
            }
            System.out.println(maxSum);
        }
    }
}