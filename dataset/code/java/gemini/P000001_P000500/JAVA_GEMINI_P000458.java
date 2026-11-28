import java.util.*;
public class Solution {
    static boolean canSplit(int[] arr, int m, long maxSum) {
        int count = 1;
        long curr = 0;
        for (int v : arr) {
            if (curr + v > maxSum) { count++; curr = v; }
            else curr += v;
        }
        return count <= m;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int[] arr = new int[n];
            long sum = 0, maxV = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
                sum += arr[i];
                if (arr[i] > maxV) maxV = arr[i];
            }
            long l = maxV, r = sum, ans = sum;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                long mid = l + (r - l) / 2;
                if (canSplit(arr, m, mid)) { ans = mid; r = mid - 1; }
                else l = mid + 1;
            }
            System.out.println(ans);
        }
    }
}