import java.util.Scanner;

public class Solution {
    private static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long num = sc.nextLong();
            long den = sc.nextLong();
            long g = gcd(num, den);
            System.out.println((num / g) + " " + (den / g));
        }
        sc.close();
    }
}