import java.util.*;
public class Solution {
    static boolean check(int[] arr, int thresh, int div) {
        long sum = 0;
        for (int v : arr) sum += (v + div - 1) / div;
        return sum <= thresh;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int thresh = scanner.nextInt();
            int[] arr = new int[n];
            int maxV = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
                if (arr[i] > maxV) maxV = arr[i];
            }
            int l = 1, r = maxV, ans = maxV;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                int mid = l + (r - l) / 2;
                if (check(arr, thresh, mid)) { ans = mid; r = mid - 1; }
                else l = mid + 1;
            }
            System.out.println(ans);
        }
    }
}