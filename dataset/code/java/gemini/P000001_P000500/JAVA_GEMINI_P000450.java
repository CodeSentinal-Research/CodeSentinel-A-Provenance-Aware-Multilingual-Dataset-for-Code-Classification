import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int l = 0, r = n - 1;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                int mid = l + (r - l) / 2;
                int missing = arr[mid] - (mid + 1);
                if (missing < k) l = mid + 1;
                else r = mid - 1;
            }
            System.out.println(l + k);
        }
    }
}