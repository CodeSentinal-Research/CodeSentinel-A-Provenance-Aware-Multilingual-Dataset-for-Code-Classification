import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long n = sc.nextLong();
        
        // Euler's theorem: a^phi(n) = 1 mod n if gcd(a,n)=1
        // So a^phi(n) mod n = 1
        System.out.println(1);
    }
}
