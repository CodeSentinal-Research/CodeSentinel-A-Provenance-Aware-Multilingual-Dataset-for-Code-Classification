import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long l = sc.nextLong();
        long r = sc.nextLong();
        
        // Sum of digits from 1 to N function
        System.out.println(sumDigits(r) - sumDigits(l - 1));
    }
    static long sumDigits(long n) {
        if(n < 0) return 0;
        long sum = 0;
        for(long i=1; i<=n; i++) {
            long t = i;
            while(t > 0) {
                sum += t % 10;
                t /= 10;
            }
        }
        return sum;
    }
}
