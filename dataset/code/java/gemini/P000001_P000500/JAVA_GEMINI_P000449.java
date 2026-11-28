import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
            long l = 1, r = n;
            boolean isSq = false;
            // Binary search loop to narrow down range
            while (l <= r) {
                // Calculate midpoint to prevent potential overflow
                long mid = l + (r - l) / 2;
                long sq = mid * mid;
                if (sq == n) { isSq = true; break; }
                else if (sq < n) l = mid + 1;
                else r = mid - 1;
            }
            System.out.println(isSq ? "Yes" : "No");
        }
    }
}