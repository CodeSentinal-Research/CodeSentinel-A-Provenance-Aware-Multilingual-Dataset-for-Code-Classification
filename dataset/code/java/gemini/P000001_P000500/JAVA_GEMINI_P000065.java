import java.util.Scanner;
public class Solution {
    private static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    private static long lcm(long a, long b) { return (a / gcd(a, b)) * b; }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long a = scanner.nextLong(), b = scanner.nextLong(), c = scanner.nextLong();
            System.out.println(lcm(lcm(a, b), c));
        }
    }
}