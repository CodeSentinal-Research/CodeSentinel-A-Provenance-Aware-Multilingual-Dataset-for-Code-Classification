import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long x = sc.nextLong();
        long y = sc.nextLong();
        
        long g = gcd(a, b);
        System.out.println((a * x + b * y) == g ? "true" : "false");
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
}
