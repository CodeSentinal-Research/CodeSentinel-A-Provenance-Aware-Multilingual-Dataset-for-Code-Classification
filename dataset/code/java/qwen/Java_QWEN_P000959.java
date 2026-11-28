import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        
        System.out.println(c % gcd(a, b) == 0 ? "true" : "false");
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
}
