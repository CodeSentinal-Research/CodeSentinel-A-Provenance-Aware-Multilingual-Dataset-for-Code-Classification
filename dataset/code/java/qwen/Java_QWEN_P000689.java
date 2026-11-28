import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(prodDigits(n));
    }
    static long prodDigits(long n) {
        if(n < 10) return n;
        return (n % 10) * prodDigits(n / 10);
    }
}
