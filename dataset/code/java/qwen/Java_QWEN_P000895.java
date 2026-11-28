import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long gcd = a;
        long temp = b;
        while(temp != 0) {
            long t = temp;
            temp = gcd % temp;
            gcd = t;
        }
        System.out.println((a / gcd) * b);
    }
}
