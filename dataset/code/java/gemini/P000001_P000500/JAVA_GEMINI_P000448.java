import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
            long l = 0, r = n, ans = 0;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                long mid = l + (r - l) / 2;
                if (mid * mid <= n) { ans = mid; l = mid + 1; }
                else r = mid - 1;
            }
            System.out.println(ans);
        }
    }
}