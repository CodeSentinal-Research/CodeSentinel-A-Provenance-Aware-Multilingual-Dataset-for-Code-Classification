import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long l = sc.nextLong();
        long r = sc.nextLong();
        
        // Count numbers in [l, r] coprime to n
        // Use inclusion-exclusion on prime factors of n
        List<Long> primes = new ArrayList<>();
        long temp = n;
        for(long i=2; i*i<=temp; i++) {
            if(temp % i == 0) {
                primes.add(i);
                while(temp % i == 0) temp /= i;
            }
        }
        if(temp > 1) primes.add(temp);
        
        int m = primes.size();
        long count = 0;
        for(int mask=0; mask<(1<<m); mask++) {
            long prod = 1;
            int bits = 0;
            for(int i=0; i<m; i++) {
                if((mask & (1<<i)) != 0) {
                    prod *= primes.get(i);
                    bits++;
                }
            }
            long terms = r/prod - (l-1)/prod;
            if(bits % 2 == 0) count += terms;
            else count -= terms;
        }
        System.out.println(count);
    }
}
