import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextLong();
            long maxP = arr[0], minP = arr[0], ans = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] < 0) {
                    long t = maxP; maxP = minP; minP = t;
                }
                maxP = Math.max(arr[i], maxP * arr[i]);
                minP = Math.min(arr[i], minP * arr[i]);
                ans = Math.max(ans, maxP);
            }
            System.out.println(ans);
        }
    }
}