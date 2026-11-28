import java.util.*;
public class Solution {
    static boolean isValid(int[] arr, int n, int m, long maxPages) {
        int students = 1;
        long curr = 0;
        for (int p : arr) {
            if (p > maxPages) return false;
            if (curr + p > maxPages) {
                students++;
                curr = p;
                if (students > m) return false;
            } else {
                curr += p;
            }
        }
        return true;
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
            if (m > n) { System.out.println(-1); return; }
            long l = maxV, r = sum, ans = sum;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                long mid = l + (r - l) / 2;
                if (isValid(arr, n, m, mid)) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            System.out.println(ans);
        }
    }
}