import java.util.*;
public class Solution {
    static boolean canShip(int[] arr, int d, long cap) {
        int days = 1;
        long curr = 0;
        for (int w : arr) {
            if (curr + w > cap) { days++; curr = w; }
            else curr += w;
        }
        return days <= d;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int d = scanner.nextInt();
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
                if (canShip(arr, d, mid)) { ans = mid; r = mid - 1; }
                else l = mid + 1;
            }
            System.out.println(ans);
        }
    }
}