import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long dividend = sc.nextLong();
        long divisor = sc.nextLong();
        
        if(dividend == Integer.MIN_VALUE && divisor == -1) {
            System.out.println(Integer.MAX_VALUE);
            return;
        }
        
        boolean negative = (dividend < 0) ^ (divisor < 0);
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        
        long quotient = 0;
        for(int i=31; i>=0; i--) {
            if((dividend >> i) >= divisor) {
                quotient += (1L << i);
                dividend -= (divisor << i);
            }
        }
        System.out.println(negative ? -quotient : quotient);
    }
}
