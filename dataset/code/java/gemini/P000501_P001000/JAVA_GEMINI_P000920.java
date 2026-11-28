import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = Math.abs(sc.nextLong());
            if (n == 0) {
                System.out.println("0 0");
                sc.close();
                return;
            }
            long minD = 9, maxD = 0;
            while (n > 0) {
                long d = n % 10;
                if (d < minD) minD = d;
                if (d > maxD) maxD = d;
                n /= 10;
            }
            System.out.println(minD + " " + maxD);
        }
        sc.close();
    }
}