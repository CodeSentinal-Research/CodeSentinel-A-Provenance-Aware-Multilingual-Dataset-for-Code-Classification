import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int l = 0, r = n - 1, idx = -1;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                int mid = l + (r - l) / 2;
                if (arr[mid] == target) { idx = mid; break; }
                else if (arr[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            System.out.println(idx);
        }
    }
}