import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n == 0) { System.out.println(0); return; }
        long prod = 1;
        while(n > 0) {
            long d = n % 10;
            if(d != 0) prod *= d;
            n /= 10;
        }
        System.out.println(prod);
    }
}
