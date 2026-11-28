import java.util.*;
public class Solution {
    static boolean canPlace(int[] arr, int c, int dist) {
        int count = 1, last = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - last >= dist) {
                count++;
                last = arr[i];
                if (count >= c) return true;
            }
        }
        return count >= c;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), c = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            Arrays.sort(arr);
            int l = 1, r = arr[n - 1] - arr[0], ans = 1;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                int mid = l + (r - l) / 2;
                if (canPlace(arr, c, mid)) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            System.out.println(ans);
        }
    }
}