import java.util.Scanner;
public class Solution {
    private static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long a = scanner.nextLong(), b = scanner.nextLong();
            long lcm = (a / gcd(a, b)) * b;
            System.out.println(lcm);
        }
    }
}