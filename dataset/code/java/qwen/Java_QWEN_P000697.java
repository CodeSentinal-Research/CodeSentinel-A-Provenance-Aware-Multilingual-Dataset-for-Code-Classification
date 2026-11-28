import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(isPrime(n, 2) ? "true" : "false");
    }
    static boolean isPrime(long n, long d) {
        if(n < 2) return false;
        if(d * d > n) return true;
        if(n % d == 0) return false;
        return isPrime(n, d + 1);
    }
}
