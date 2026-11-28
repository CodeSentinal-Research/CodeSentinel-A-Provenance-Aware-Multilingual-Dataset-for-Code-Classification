import java.util.*;
public class Solution {
    // Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(vals[i]);
                if (i + 1 < n) sb.append(" ").append(gcd(vals[i], vals[i + 1])).append(" ");
            }
            System.out.println(sb.toString().trim());
        }
    }
}