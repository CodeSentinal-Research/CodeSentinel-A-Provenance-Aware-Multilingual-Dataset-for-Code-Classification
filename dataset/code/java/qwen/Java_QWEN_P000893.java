import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        Set<Long> factors = new TreeSet<>();
        for(long i=2; i*i<=n; i++) {
            while(n % i == 0) {
                factors.add(i);
                n /= i;
            }
        }
        if(n > 1) factors.add(n);
        for(long f : factors) System.out.print(f + " ");
    }
}
