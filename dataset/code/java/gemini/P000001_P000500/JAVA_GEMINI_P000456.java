import java.util.*;
public class Solution {
    static boolean canFinish(int[] arr, int h, long speed) {
        long hours = 0;
        for (int p : arr) hours += (p + speed - 1) / speed;
        return hours <= h;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int h = scanner.nextInt();
            int[] arr = new int[n];
            int maxV = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
                if (arr[i] > maxV) maxV = arr[i];
            }
            long l = 1, r = maxV, ans = maxV;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                long mid = l + (r - l) / 2;
                if (canFinish(arr, h, mid)) { ans = mid; r = mid - 1; }
                else l = mid + 1;
            }
            System.out.println(ans);
        }
    }
}