import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long orig = n;
        int digits = String.valueOf(n).length();
        long sum = 0;
        while(n > 0) {
            long d = n % 10;
            long p = 1;
            for(int i=0; i<digits; i++) p *= d;
            sum += p;
            n /= 10;
        }
        System.out.println(sum == orig ? "true" : "false");
    }
}
