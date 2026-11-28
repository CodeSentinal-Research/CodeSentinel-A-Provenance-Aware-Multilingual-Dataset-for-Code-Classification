import java.util.*;
public class Solution {
    static long climbStairs(int n) {
        if (n <= 1) return 1;
        long a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            long c = a + b; a = b; b = c;
        }
        return b;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            System.out.println(climbStairs(scanner.nextInt()));
        }
    }
}