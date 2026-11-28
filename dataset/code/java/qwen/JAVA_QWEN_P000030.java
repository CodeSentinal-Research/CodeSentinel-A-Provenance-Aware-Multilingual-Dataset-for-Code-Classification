import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long gcd = a;
        long tempB = b;
        while (tempB != 0) {
            long t = tempB;
            tempB = gcd % tempB;
            gcd = t;
        }
        System.out.println((a * b) / gcd);
    }
}
