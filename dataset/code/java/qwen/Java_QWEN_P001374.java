import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        while(n != 1) {
            long sum = 0;
            long t = n;
            while(t > 0) {
                long d = t % 10;
                sum += d * d;
                t /= 10;
            }
            n = sum;
            if(n == 4) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
