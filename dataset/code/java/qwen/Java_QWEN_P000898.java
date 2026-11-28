import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        long den = sc.nextLong();
        
        long gcd = gcd(num, den);
        System.out.println((num/gcd) + " " + (den/gcd));
    }
    static long gcd(long a, long b) {
        while(b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
